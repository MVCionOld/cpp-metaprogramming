#ifndef HW3_TYPELIST_H
#define HW3_TYPELIST_H

namespace typelist {

  //
  // Define TypeList
  //

  class NullType {
  };

  class __NonExistentType {
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

  typedef TypeList<> EmptyTypeList;

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
            typename TypeList<K...>::Tail>::res>;
  };

  template<typename U, typename T>
  struct Add<U, 0, T> {
    using res = TypeList<U, T>;
  };

  template<typename U, size_t ind>
  struct Add<U, ind, TypeList<NullType>> {
    using res = U;
  };

  // #5 RemoveAll

  template<typename U, typename ...T>
  struct RemoveAll;

  template<typename U, typename ...T>
  struct RemoveAll<U, TypeList<T...>> {
    using res = TypeList<
        typename TypeList<T...>::Head,
        typename RemoveAll<
            U,
            typename TypeList<T...>::Tail>::res>;
  };

  template<typename T, typename ...K>
  struct RemoveAll<T, TypeList<T, K...>> {
    using res = typename RemoveAll<T, typename TypeList<T, K...>::Tail>::res;
  };

  template<typename T>
  struct RemoveAll<T, EmptyTypeList> {
    using res = NullType;
  };

  // #*extra1 Join

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

  // #*extra2 Flatten

  template<class T>
  struct Flatten {
    using res = TypeList<T>;
  };

  template<class ...T>
  struct Flatten<TypeList<T...>> {
    using res = typename Join<typename Flatten<T>::res...>::res;
  };

  // #6 Remove

  template<typename U, typename ...T>
  struct Remove;

  template<typename U, typename ...T>
  struct Remove<U, TypeList<T...>> {
    using res =
    typename Flatten<
        TypeList<
            typename TypeList<T...>::Head,
            typename Remove<
                U,
                typename TypeList<T...>::Tail
            >::res
        >
    >::res;
  };

  template<typename T, typename ...K>
  struct Remove<T, TypeList<T, K...>> {
    using res = typename Remove<__NonExistentType, TypeList<K...>>::res;
  };

  template<typename T>
  struct Remove<T, EmptyTypeList> {
    using res = NullType;
  };

  // #7 NoDuplicates

  template<typename ...T>
  struct NoDuplicates;

  template<typename T>
  struct NoDuplicates<TypeList<T>> {
  private:
    using tailWithoutHead = TypeList<T>;
    using tailWithoutDublicates = TypeList<T>;
  public:
    using res = TypeList<T>;
  };

  template<>
  struct NoDuplicates<EmptyTypeList> {
  private:
    using tailWithoutHead = NullType;
    using tailWithoutDublicates = NullType;
  public:
    using res = NullType;
  };

  template<typename ...T>
  struct NoDuplicates<TypeList<T...>> {
  private:
    using tailWithoutHead =
    typename Flatten<
        typename RemoveAll<
            typename TypeList<T...>::Head,
            typename TypeList<T...>::Tail
        >::res
    >::res;
    using tailWithoutDublicates =
    typename Flatten<
        typename NoDuplicates<tailWithoutHead>::res
    >::res;
  public:
    using res =
    typename Flatten<
        typename RemoveAll<
            NullType,
            typename Flatten<
                TypeList<
                    typename TypeList<T...>::Head,
                    tailWithoutDublicates
                >
            >::res
        >::res
    >::res;
  };

};


#endif //HW3_TYPELIST_H
