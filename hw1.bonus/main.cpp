#include <iostream>


namespace typelist {

    //
    // Define TypeList
    //

    struct NullType;

    template <typename ...T>
    struct TypeList {};

    template <typename H, typename X, typename ...T>
    struct TypeList<H, X, T...> {
        using Head = H;
        using Tail = TypeList<X, T...>;
    };

    template <typename H, typename T>
    struct TypeList<H, T> {
        using Head = H;
        using Tail = TypeList<T>;
    };

    template <typename H>
    struct TypeList<H> {
        using Head = H;
        using Tail = NullType;
    };

    using EmptyTypeList = TypeList<>;

    //
    // Define meta functions
    //

    // #1 Length

    template <typename T>
    struct Length {
        static const size_t val = 1 + Length<typename T::Tail>::val;
    };

    template <>
    struct Length<NullType> {
        static const size_t val = 0;
    };

    // #2 TypeAt

    template <typename T, size_t idx>
    struct TypeAt {
        using res = typename TypeAt<typename T::Tail, idx-1>::res;
    };

    template <>
    struct TypeAt<NullType, 0> {
        using res = NullType;
    };

    template <size_t idx>
    struct TypeAt<NullType, idx> {
        using res = NullType;
    };

    template <typename T>
    struct TypeAt<T, 0> {
        using res = typename T::Head;
    };

    // #3 IndexOf

    template<typename T, typename U>
    struct IndexOf {};

    template <typename T, typename ...K, typename U>
    struct IndexOf<TypeList<T, K...>, U> {
        static const ssize_t val = 1 + IndexOf<TypeList<K...>, U>::val;
    };

    template<typename T>
    struct IndexOf<EmptyTypeList, T> {
        static const ssize_t val = std::numeric_limits<ssize_t>::min();
    };

    template<typename T, typename ...K>
    struct IndexOf<TypeList<T, K...>, T> {
        static const ssize_t val = 0;
    };

    // #4 Add

    template <typename T, typename U, size_t idx>
    struct Add {
        using res = TypeList<
            typename T::Head,
            typename Add<typename T::Tail, U, idx-1>::res
        >;
    };

    template <typename T, typename U>
    struct Add<T, U, 0> {
        using res = TypeList<U, T>;
    };

    template <typename U, size_t idx>
    struct Add<NullType, U, idx> {
        using res = U;
    };

    template <typename U>
    struct Add<NullType, U, 0> {
        using res = U;
    };

    // #5 Remove

    template <typename T, typename U>
    struct Remove {
        using res = TypeList<
            typename T::Head,
            typename Remove<typename T::Tail, U>::res
        >;
    };

    template <typename U>
    struct Remove<NullType, U> {
        using res = NullType;
    };

    template <typename T, typename ...U>
    struct Remove<TypeList<T, U...>, T> {
        using res = TypeList<U...>;
    };

    // #6 RemoveAll

    template <typename T, typename U>
    struct RemoveAll {
        using res = TypeList<
            typename T::Head,
            typename RemoveAll<typename T::Tail, U>::res
        >;
    };

    template <typename T>
    struct RemoveAll<NullType, T> {
        using res = NullType;
    };

    template <typename T, typename ...U>
    struct RemoveAll<TypeList<T, U...>, T> {
        using res = typename RemoveAll<TypeList<U...>, T>::res;
    };

    // #7 NoDuplicates

    template <typename T>
    struct NoDuplicates {
        using res = TypeList<
            typename T::Head,
            typename NoDuplicates<
                typename RemoveAll<
                    typename T::Tail,
                    typename T::Head
                >::res
            >::res
        >;
    };

    template <>
    struct NoDuplicates<NullType> {
        using res = NullType;
    };

};

using namespace typelist;


int main() {

    Remove<TypeList<int, char, float, float, char, int, float, double>, double>::res a = 2;

    // , int, char, float, float, char, int, double, float, double
    return 0;
}


