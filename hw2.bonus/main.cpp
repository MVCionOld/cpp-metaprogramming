#include <iostream>

class A {};
class BA {};
class BA1 : public BA {};
class BA2 : public BA {};
class BA11 : public BA1 {};
class BB {};
class BB1 : public BB {};
class BB2 : public BB {};
class BB21 : public BB2 {};


class Nulltype {};

template<typename ...Args>
struct TypeList {
    using Head = Nulltype;
    using Tail = Nulltype;
};

template<typename H, typename ...T>
struct TypeList<H, T...> {
    using Head = H;
    using Tail = TypeList<T...>;
};

typedef TypeList<> EmptyTypeList;

template<typename H>
struct TypeList<H> {
    using Head = H;
    using Tail = EmptyTypeList;
};



//...................................................................//


template<typename T>
struct Length {
    static const int value = 1 + Length<T::Tail>::value;
};

template<>
struct Length<Nulltype> {
    static const int value = 0;
};

//...................................................................//

template<size_t ind, typename ...T>
struct TypeAt {
    using res = Nulltype;
};

template<size_t ind, typename ...T>
struct TypeAt<ind, TypeList<T...>> {
    using res = typename TypeAt<ind - 1, typename TypeList<T...>::Tail>::res;
};

template<size_t ind>
struct TypeAt<ind, Nulltype> {
    using res = Nulltype;
};

template<typename ...T>
struct TypeAt<0, TypeList<T...>> {
    using res = typename TypeList<T...>::Head;
};

//...................................................................//

template<typename U, typename ...T>
struct IndexOf {
    static const size_t value = 1;
};

template<typename ...K, typename U>
struct IndexOf<U, TypeList<K...>> {
    static const size_t value = 1 + IndexOf<U, typename TypeList<K...>::Tail>::value;
};

template<typename T, typename ...K>
struct IndexOf<TypeList<T, K...>, T> {
    static const size_t value = 0;
};

//...................................................................//

template<typename U, size_t ind, typename ...T>
struct Add;


template<typename U, size_t ind, typename ...K>
struct Add<U, ind, TypeList<K...> > {
    using result = TypeList<typename TypeList<K...>::Head, typename Add<U,
            ind - 1, typename TypeList<K...>::Tail>::result>;
};

template<typename U, typename T>
struct Add<U, 0, T> {
    using result = TypeList<U, T>;
};

template<typename U, size_t ind>
struct Add<U, ind, TypeList<Nulltype>> {
    using result = U;
};

//...................................................................//

template<typename U, typename ...T>
struct Remove;

template<typename U, typename ...T>
struct Remove<U, TypeList<T...>> {
    using result = TypeList<typename TypeList<T...>::Head, typename Remove<U, typename TypeList<T...>::Tail>::result>;
};

template<typename T, typename ...K>
struct Remove<T, TypeList<T, K...>> {
    using result = typename Remove<T, typename TypeList<T, K...>::Tail>::result;
};

template<typename T>
struct Remove<T, EmptyTypeList> {
    using result = Nulltype;
};

//...................................................................//

template<class T, class U, class V>
struct Replace;

template<class U, class V>
struct Replace<Nulltype, U, V> {
    using res = TypeList<Nulltype>;
};

template<class ...T, class U, class V>
struct Replace<TypeList<U, T...>, U, V> {
    using res = TypeList<V, T...>;
};

template<class ...T, class U, class V>
struct Replace<TypeList<T...>, U, V> {
    using res = TypeList<typename TypeList<T...>::Head,
            typename Replace<typename TypeList<T...>::Tail, U, V>::res>;
};



//...................................................................//

template<bool is, typename T, typename U>
struct Select;

template<typename T, typename U>
struct Select<true, T, U> {
    using res = T;
};

template<typename T, typename U>
struct Select<false, T, U> {
    using res = U;
};

//...................................................................//

template<typename T, typename U>
class Conversion {
    using Small = char;
    struct Big {
        char x[2];
    };

    static Small Test(const U &);

    static Big Test(...);

    static T makeT();

public:
    static constexpr bool exists = sizeof(Small) == sizeof(Test(makeT()));
    static constexpr bool equal = false;
};

template<typename T>
class Conversion<T, T> {
public:
    static constexpr bool exists = true;
    static constexpr bool equal = true;
};

template<bool one, bool two>
struct ANDNOT {
    static constexpr bool res = false;
};

template<>
struct ANDNOT<true, false> {
    static constexpr bool res = true;
};

template<typename T, typename U>
struct isBase {
    static constexpr bool res = ANDNOT<Conversion<T, U>::exists, Conversion<T, U>::equal>::res;
};



//...................................................................//

template<class TList, class T>
struct MostDerived;

template<class T>
struct MostDerived<Nulltype, T> {
    using res = T;
};

template<class ...TList, class T>
struct MostDerived<TypeList<TList...>, T> {
    using Cand = typename MostDerived<typename TypeList<TList...>::Tail, T>::res;

    using res = typename Select<isBase<typename TypeList<TList...>::Head, Cand>::res,
            typename TypeList<TList...>::Head, Cand>::res;
};

template<class T>
struct DerivedToFront {
    using res = Nulltype;
};

template<>
struct DerivedToFront<TypeList<Nulltype>> {
    using res = Nulltype;
};

template<typename H>
struct DerivedToFront<TypeList<H>> {
    using res = H;
};

template<typename ...TList>
struct DerivedToFront<TypeList<TList...>> {
private:

    using TheMostDerived = typename MostDerived<typename TypeList<TList...>::Tail, typename TypeList<TList...>::Head>::res;

    using Temp = typename Replace<typename TypeList<TList...>::Tail, TheMostDerived, typename TypeList<TList...>::Head>::res;

    using L = typename DerivedToFront<Temp>::res;

public:
    using res = TypeList<TheMostDerived, L>;

};


int main() {
    TypeList<int, int, float, A> a;

    const int v = Length<TypeList<int, int, float, A, A>>::value;

    TypeAt<2, TypeList<int, int, float, A>>::res c = 1.f;

    size_t i = IndexOf<TypeList<int, float, double>, double>::value;

    Add<char, 1, TypeList<int, float, double>>::result d;

    Remove<char, TypeList<int, char, float, char, double>>::result e;

    Replace<TypeList<int, float, double>, double, char>::res rp;

    MostDerived<TypeList<BB, BA1, BB21, BA2, BA, BB2, BB1>, BB>::res md;

    //Replace<TypeList<BB, BA1, BB21, BA2, BA, BB2, BB1>, MostDerived<TypeList<BB, BA1, BB21, BA2, BA, BB2, BB1, BA>, BA>::res, BB>::res;

    constexpr bool isb = isBase<BA1, BA>::res;
    constexpr bool isc = Conversion<BA1, BA>::exists;

    std::cout << Conversion<BA1, BA>::exists;

    DerivedToFront<TypeList<BB, BA1, BB21, BA2, BA, BB2, BB1>>::res dtf;

}