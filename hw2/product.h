//
// Created by mvcibuntu on 15.11.2020.
//

#ifndef HW2_PRODUCT_H
#define HW2_PRODUCT_H

#include <string>

namespace product {

    class Product {
    public:
        Product() : id("Product") {}

        std::string identify() {
            return id;
        }

    protected:
        std::string id;
    };

    /*       Product
     *     /    |   \
     *  Chair Table Sofa
     */

    class Chair : public Product {
    public:
        Chair() { id = "Chair"; }
    };

    class Table : public Product {
    public:
        Table() { id = "Table"; }
    };

    class Sofa : public Product {
    public:
        Sofa() { id = "Sofa"; }
    };

    /*             Chair
     *            /  |  \
     *  WoodenChair  |   MetalChair
     *               |
     *          PlasticChair
     */

    class WoodenChair : public Chair {
    public:
        WoodenChair() { id = "WoodenChair"; }
    };

    class PlasticChair : public Chair {
    public:
        PlasticChair() { id = "PlasticChair"; }
    };

    class MetalChair : public Chair {
    public:
        MetalChair() { id = "MetalChair"; }
    };

    /*             Table
     *            /  |  \
     *  WoodenTable  |   MetalTable
     *               |
     *          PlasticTable
     */

    class WoodenTable : public Table {
    public:
        WoodenTable() { id = "WoodenTable"; }
    };

    class PlasticTable : public Table {
    public:
        PlasticTable() { id = "PlasticTable"; }
    };

    class MetalTable : public Table {
    public:
        MetalTable() { id = "MetalTable"; }
    };

    /*              Sofa
     *            /  |  \
     *  WoodenSofa   |   MetalSofa
     *               |
     *          PlasticSofa
     */

    class WoodenSofa : public Sofa {
    public:
        WoodenSofa() { id = "WoodenSofa"; }
    };

    class PlasticSofa : public Sofa {
    public:
        PlasticSofa() { id = "PlasticSofa"; }
    };

    class MetalSofa : public Sofa {
    public:
        MetalSofa() { id = "MetalSofa"; }
    };

    /*                WoodenChair
     *                  /  |  \
     *  ItalicWoodenChair  |   RussianWoodenChair
     *                     |
     *              GermanWoodenChair
     */

    class ItalicWoodenChair : public WoodenChair {
    public:
        ItalicWoodenChair() { id = "ItalicWoodenChair"; }
    };

    class GermanWoodenChair : public WoodenChair {
    public:
        GermanWoodenChair() { id = "GermanWoodenChair"; }
    };

    class RussianWoodenChair : public WoodenChair {
    public:
        RussianWoodenChair() { id = "RussianWoodenChair"; }
    };

    /*                 PlasticChair
     *                   /  |  \
     *  ItalicPlasticChair  |   RussianPlasticChair
     *                      |
     *              GermanPlasticChair
     */

    class ItalicPlasticChair : public PlasticChair {
    public:
        ItalicPlasticChair() { id = "ItalicPlasticChair"; }
    };

    class GermanPlasticChair : public PlasticChair {
    public:
        GermanPlasticChair() { id = "GermanPlasticChair"; }
    };

    class RussianPlasticChair : public PlasticChair {
    public:
        RussianPlasticChair() { id = "RussianPlasticChair"; }
    };

    /*                 MetalChair
     *                  /  |  \
     *   ItalicMetalChair  |   RussianMetalChair
     *                     |
     *              GermanMetalChair
     */

    class ItalicMetalChair : public MetalChair {
    public:
        ItalicMetalChair() { id = "ItalicMetalChair"; }
    };

    class GermanMetalChair : public MetalChair {
    public:
        GermanMetalChair() { id = "GermanMetalChair"; }
    };

    class RussianMetalChair : public MetalChair {
    public:
        RussianMetalChair() { id = "RussianMetalChair"; }
    };

    /*                WoodenTable
     *                  /  |  \
     *  ItalicWoodenTable  |   RussianWoodenTable
     *                     |
     *              GermanWoodenTable
     */

    class ItalicWoodenTable : public WoodenTable {
    public:
        ItalicWoodenTable() { id = "ItalicWoodenTable"; }
    };

    class GermanWoodenTable : public WoodenTable {
    public:
        GermanWoodenTable() { id = "GermanWoodenTable"; }
    };

    class RussianWoodenTable : public WoodenTable {
    public:
        RussianWoodenTable() { id = "RussianWoodenTable"; }
    };

    /*                 PlasticTable
     *                   /  |  \
     *  ItalicPlasticTable  |   RussianPlasticTable
     *                      |
     *              GermanPlasticTable
     */

    class ItalicPlasticTable : public PlasticTable {
    public:
        ItalicPlasticTable() { id = "ItalicPlasticTable"; }
    };

    class GermanPlasticTable : public PlasticTable {
    public:
        GermanPlasticTable() { id = "GermanPlasticTable"; }
    };

    class RussianPlasticTable : public PlasticTable {
    public:
        RussianPlasticTable() { id = "RussianPlasticTable"; }
    };

    /*                 MetalTable
     *                  /  |  \
     *   ItalicMetalTable  |   RussianMetalTable
     *                     |
     *              GermanMetalTable
     */

    class ItalicMetalTable : public MetalTable {
    public:
        ItalicMetalTable() { id = "ItalicMetalTable"; }
    };

    class GermanMetalTable : public MetalTable {
    public:
        GermanMetalTable() { id = "GermanMetalTable"; }
    };

    class RussianMetalTable : public MetalTable {
    public:
        RussianMetalTable() { id = "RussianMetalTable"; }
    };

    /*                WoodenSofa
     *                  /  |  \
     *   ItalicWoodenSofa  |   RussianWoodenSofa
     *                     |
     *              GermanWoodenSofa
     */

    class ItalicWoodenSofa : public WoodenSofa {
    public:
        ItalicWoodenSofa() { id = "ItalicWoodenSofa"; }
    };

    class GermanWoodenSofa : public WoodenSofa {
    public:
        GermanWoodenSofa() { id = "GermanWoodenSofa"; }
    };

    class RussianWoodenSofa : public WoodenSofa {
    public:
        RussianWoodenSofa() { id = "RussianWoodenSofa"; }
    };

    /*                 PlasticSofa
     *                   /  |  \
     *   ItalicPlasticSofa  |   RussianPlasticSofa
     *                      |
     *              GermanPlasticSofa
     */

    class ItalicPlasticSofa : public PlasticSofa {
    public:
        ItalicPlasticSofa() { id = "ItalicPlasticSofa"; }
    };

    class GermanPlasticSofa : public PlasticSofa {
    public:
        GermanPlasticSofa() { id = "GermanPlasticSofa"; }
    };

    class RussianPlasticSofa : public PlasticSofa {
    public:
        RussianPlasticSofa() { id = "RussianPlasticSofa"; }
    };

    /*                 MetalSofa
     *                  /  |  \
     *    ItalicMetalSofa  |   RussianMetalSofa
     *                     |
     *              GermanMetalSofa
     */

    class ItalicMetalSofa : public MetalSofa {
    public:
        ItalicMetalSofa() { id = "ItalicMetalSofa"; }
    };

    class GermanMetalSofa : public MetalSofa {
    public:
        GermanMetalSofa() { id = "GermanMetalSofa"; }
    };

    class RussianMetalSofa : public MetalSofa {
    public:
        RussianMetalSofa() { id = "RussianMetalSofa"; }
    };

};

#endif //HW2_PRODUCT_H
