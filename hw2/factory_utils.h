//
// Created by mvcibuntu on 15.11.2020.
//

#ifndef HW2_FACTORY_UTILS_H
#define HW2_FACTORY_UTILS_H

#include <type_traits>

#include "conversion.h"
#include "hierarchy.h"

namespace factory_utils {

    template<bool condition, class IfTrueType, class IfFalseType>
    struct Conditional;

    template<class IfTrueType, class IfFalseType>
    struct Conditional</* condition = */true, IfTrueType, IfFalseType> {
        using res = IfTrueType;
    };

    template<class IfTrueType, class IfFalseType>
    struct Conditional</* condition = */false, IfTrueType, IfFalseType> {
        using res = IfFalseType;
    };

    template <typename... TLists>
    struct Bases;

    template <typename Head, typename... Tail, typename TList, typename... TLists>
    struct Bases<typelist::TypeList<Head, Tail...>, TList, TLists...> {
    private:
        using basesTypeList = typename Bases<TList, TLists...>::res;
    public:
        using res = typename Conditional<
            /* Condition   = */conversion::IsBase<Head, typename basesTypeList::Head>::res,
            /* IfTrueType  = */typelist::TypeList<Head, Tail...>,
            /* IfFalseType = */basesTypeList
        >::res;
    };

    template <typename TList>
    struct Bases<TList> {
        using res = TList;
    };

    template <typename T, typename Head, typename... Tail>
    struct MultiFind;

    template <typename T, typename Head, typename... Tail>
    struct MultiFind<T, typelist::TypeList<Head, Tail...>> {
        using res = typename Conditional<
            /* Condition   = */typelist::Contains<T, Head>::res,
            /* IfTrueType  = */Head,
            /* IfFalseType = */typename MultiFind<T, typelist::TypeList<Tail...>>::res
        >::res;
    };

    template <typename T>
    struct MultiFind<T, typelist::EmptyTypeList> {
        using res = typelist::EmptyTypeList;
    };
};

#endif //HW2_FACTORY_UTILS_H
