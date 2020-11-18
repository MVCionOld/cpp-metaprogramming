//
// Created by mvcibuntu on 15.11.2020.
//

#ifndef HW2_TYPELIST_H
#define HW2_TYPELIST_H

#include <cstdlib>

namespace typelist {

    //
    // Define TypeList
    //

    class NullType {
    };

    template<typename ...Args>
    struct TypeList {
        using Head = NullType;
        using Tail = NullType;
    };

    template<typename H, typename ...T>
    struct TypeList<H, T...> {
        using Head = H;
        using Tail = TypeList<T...>;
    };

    using EmptyTypeList = TypeList<>;

    template<typename H>
    struct TypeList<H> {
        using Head = H;
        using Tail = EmptyTypeList;
    };

    //
    // Define meta functions
    //

    // #1 Length

    template<typename T>
    struct Length {
        static const size_t val = 1 + Length<typename T::Tail>::val;
    };

    template<>
    struct Length<NullType> {
        static const size_t val = 0;
    };

    // #2 TypeAt

    template<size_t idx, typename ...T>
    struct TypeAt {
        using res = NullType;
    };

    template<size_t idx, typename ...T>
    struct TypeAt<idx, TypeList<T...>> {
        using res = typename TypeAt<idx - 1, typename TypeList<T...>::Tail>::res;
    };

    template<size_t idx>
    struct TypeAt<idx, NullType> {
        using res = NullType;
    };

    template<typename ...T>
    struct TypeAt<0, TypeList<T...>> {
        using res = typename TypeList<T...>::Head;
    };

    // #3 IndexOf

    template<typename U, typename ...T>
    struct IndexOf {
        static const size_t val = 1;
    };

    template<typename ...K, typename U>
    struct IndexOf<U, TypeList<K...>> {
        static const size_t val = 1 + IndexOf<U, typename TypeList<K...>::Tail>::val;
    };

    template<typename T, typename ...K>
    struct IndexOf<TypeList<T, K...>, T> {
        static const size_t val = 0;
    };

    // #4 Add

    template<typename U, size_t idx, typename ...T>
    struct Add;

    template<typename U, size_t idx, typename ...K>
    struct Add<U, idx, TypeList<K...>> {
        using res = TypeList<
            typename TypeList<K...>::Head,
            typename Add<
                U,
                idx - 1,
                typename TypeList<K...>::Tail
            >::res
        >;
    };

    template<typename U, typename T>
    struct Add<U, 0, T> {
        using res = TypeList<U, T>;
    };

    template<typename U, size_t ind>
    struct Add<U, ind, TypeList<NullType>> {
        using res = U;
    };

    // #5 Join

    template<class ...T>
    struct Join {
        using res = NullType;
    };

    template<class ...T>
    struct Join<TypeList<T...>> {
        using res = TypeList<T...>;
    };

    template<class ...T, class ...K, class ... U>
    struct Join<TypeList<T...>, TypeList<K...>, U...> {
        using res = typename Join<TypeList<T..., K...>, U...>::res;
    };

    // #6 Flatten

    template<class T>
    struct Flatten {
        using res = TypeList<T>;
    };

    template<class ...T>
    struct Flatten<TypeList<T...>> {
        using res = typename Join<typename Flatten<T>::res...>::res;
    };

    // #7 Reverse

    template <typename T> struct Reverse;

    template <typename H, typename... T>
    struct Reverse<TypeList<H, T...>> {
        using reversedTail = typename Reverse<TypeList<T...> >::res;
        using res = typename Join<reversedTail, TypeList<H>>::res;
    };

    template <>
    struct Reverse<EmptyTypeList> {
        using res = EmptyTypeList;
    };

    // #8 Contains

    template <typename T, typename TList>
    struct Contains;

    template <typename T>
    struct Contains<T, EmptyTypeList> {
        static const bool res = false;
    };

    template <typename T, typename... Tail>
    struct Contains<T, TypeList<T, Tail...>> {
        static const bool res = true;
    };

    template <typename T, typename Head, typename... Tail>
    struct Contains<T, TypeList<Head, Tail...>> {
        static const bool res = Contains<T, TypeList<Tail...>>::res;
    };

};

#endif //HW2_TYPELIST_H
