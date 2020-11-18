//
// Created by mvcibuntu on 15.11.2020.
//

#ifndef HW2_HIERARCHY_H
#define HW2_HIERARCHY_H

#include "typelist.h"

namespace hierarchy {

    /* from lecture */
    template <typename TList, template <class> class Unit>
    struct ScatterHierarchyGenerator;

    template <typename ...TList, template <class> class Unit>
    struct ScatterHierarchyGenerator<typelist::TypeList<TList...>, Unit> :
            public ScatterHierarchyGenerator<typename typelist::TypeList<TList...>::Tail, Unit>,
            public Unit<typename typelist::TypeList<TList...>::Head> {
        using LeftBase = Unit<typename typelist::TypeList<TList...>::Head>;
        using RightBase = ScatterHierarchyGenerator<typename typelist::TypeList<TList...>::Tail, Unit>;
    };

    template <class T, template <class> class Unit>
    struct ScatterHierarchyGenerator <typelist::TypeList<T>, Unit> :
            public Unit<T> {
        using LeftBase = Unit<T>;
        using RightBase = typelist::NullType;
    };

    /* from lecture */
    template <
        typename TList,
        template <class, class> class Unit,
        typename Root=typelist::NullType
    > struct LinearHierarchyGenerator;

    template <
        typename ...TList,
        template <class, class> class Unit,
        typename Root
    > struct LinearHierarchyGenerator<typelist::TypeList<TList...>, Unit, Root> :
            public Unit<typename typelist::TypeList<TList...>::Head,
            LinearHierarchyGenerator<typename typelist::TypeList<TList...>::Tail, Unit, Root>> {};

    template <
        typename TList,
        template <class, class> class Unit,
        typename Root
    > struct LinearHierarchyGenerator<typelist::TypeList<TList>, Unit, Root> :
            public Unit<TList, Root> {};

};

#endif //HW2_HIERARCHY_H
