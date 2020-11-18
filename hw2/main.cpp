#include <cassert>
#include <iostream>
#include <memory>

#include "factory.h"
#include "product.h"
#include "typelist.h"


using namespace product;
using FactoryHierarchy = factory::GetAbstractFactory<
    /* N         = */3,
    /* M         = */5,
    /* ...TLists = */
    typelist::TypeList<Chair, Table, Sofa>,
    typelist::TypeList<WoodenChair, WoodenTable, WoodenSofa>,
    typelist::TypeList<MetalChair, MetalTable, MetalSofa>,
    typelist::TypeList<ItalicMetalChair, ItalicMetalTable, ItalicMetalSofa>,
    typelist::TypeList<RussianMetalChair, RussianMetalTable, RussianMetalSofa>
>;


struct FurnitureIdentity {
    std::string chairIdentity;
    std::string sofaIdentity;
    std::string tableIdentity;
};

template<typename ConcreteProductType>
void AssertFurniteFactory(
        const std::string& assertationTopic,
        const struct FurnitureIdentity& furnitureIdentity
) {
    std::cout << std::endl << "Assertation section: \"" << assertationTopic << "\":" << std::endl;

    std::unique_ptr<FactoryHierarchy::Factory> factory{
        new typename FactoryHierarchy::GetConcreteFactory<ConcreteProductType>::res
    };

    std::unique_ptr<Product> chair{factory->Get<Chair>()};
    std::unique_ptr<Product> sofa{factory->Get<Sofa>()};
    std::unique_ptr<Product> table{factory->Get<Table>()};

    assert(chair->identify() == furnitureIdentity.chairIdentity);
    assert(sofa->identify()  == furnitureIdentity.sofaIdentity);
    assert(table->identify() == furnitureIdentity.tableIdentity);

    std::cout << "\tAssertation passed!" << std::endl;
}


int main() {

    AssertFurniteFactory<Chair>("Default furniture", (struct FurnitureIdentity) {
            .chairIdentity="Chair",
            .sofaIdentity="Sofa",
            .tableIdentity="Table"
    });

    AssertFurniteFactory<WoodenSofa>("Wooden furniture", (struct FurnitureIdentity) {
            .chairIdentity="WoodenChair",
            .sofaIdentity="WoodenSofa",
            .tableIdentity="WoodenTable"
    });

    AssertFurniteFactory<ItalicMetalTable>("Italic metal furniture", (struct FurnitureIdentity) {
            .chairIdentity="ItalicMetalChair",
            .sofaIdentity="ItalicMetalSofa",
            .tableIdentity="ItalicMetalTable"
    });

    AssertFurniteFactory<RussianMetalTable>("Russian metal furniture", (struct FurnitureIdentity) {
            .chairIdentity="RussianMetalChair",
            .sofaIdentity="RussianMetalSofa",
            .tableIdentity="RussianMetalTable"
    });

    return 0;
}