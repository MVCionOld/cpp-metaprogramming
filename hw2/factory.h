//
// Created by mvcibuntu on 15.11.2020.
//

#ifndef HW2_FACTORY_H
#define HW2_FACTORY_H

#include "conversion.h"
#include "factory_utils.h"
#include "hierarchy.h"

namespace factory {

    template <typename T>
    struct AbstractUnit {
        virtual T* Get(T)=0;
        virtual ~AbstractUnit()=default;
    };


    template <typename BaseProductTypeList>
    struct AbstractFactory: // scatter hierarchy generator for generating AbstractFactory
            public hierarchy::ScatterHierarchyGenerator<BaseProductTypeList, AbstractUnit> {
        using ProductTypeList = BaseProductTypeList;

        template <typename T>
        T* Get() {
            AbstractUnit<T>& unit = *this;
            return unit.Get(conversion::TypeManipHelper<T>().makeT());
        }
    };


    template <class ConcreteProduct, class Base>
    struct ConcreteUnit: public Base { // linear hierarchy
        using BaseProductTypeList = typename Base::ProductTypeList;
        using BaseProductType = typename BaseProductTypeList::Head;
        using ProductTypeList = typename BaseProductTypeList::Tail;

        ConcreteProduct* Get(BaseProductType) override {
            return new ConcreteProduct;
        }
    };


    template <
        typename AbstractFactoryType,
        typename TList
    > struct ConcreteFactory: // linear hierarchy generator for generating ConcreteFactory from AbstractFactory
            public hierarchy::LinearHierarchyGenerator<
                /* TList = */TList,
                /* Unit  = */ConcreteUnit,
                /* Root  = */AbstractFactoryType
            > {
        using ProductTypeList = typename AbstractFactoryType::ProductTypeList;
    };


    template <size_t N, size_t M, typename ...TLists>
    struct GetAbstractFactory {
        using Factory = AbstractFactory<
            /* BaseProductTypesList =*/typename factory_utils::Bases<TLists...>::res
        >;

        template <typename T>
        struct GetConcreteFactory {
            using res = ConcreteFactory<
                /* AbstractFactoryType = */Factory,
                /* TList               = */typename typelist::Reverse<
                    typename factory_utils::MultiFind<
                        /* T     = */T,
                        /* TList = */typelist::TypeList<TLists...>
                    >::res
                >::res
            >;
        };
    };

};

#endif //HW2_FACTORY_H
