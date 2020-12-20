#ifndef HW3_METAGRAPHVERTICES_H
#define HW3_METAGRAPHVERTICES_H

#include <memory>
#include "TypeList/TypeList.h"

template<class TVertices>
struct MetaGraphVertices;

template<size_t idx>
struct AdjacencyMatrixGraphVerticesGet;

template<size_t idx>
struct AdjacencyMatrixGraphVerticesSet;

template<typename ...Args>
class MetaGraphVertices<typelist::TypeList < Args...>>
{
public:
  using Head = typename typelist::TypeList<Args...>::Head;
  using Tail = typename typelist::TypeList<Args...>::Tail;

  MetaGraphVertices ()
    : upVertex(std::make_unique<Head>()) {}

  template<size_t idx> friend struct AdjacencyMatrixGraphVerticesGet;
  template<size_t idx> friend struct AdjacencyMatrixGraphVerticesSet;

private:
  std::unique_ptr<Head> upVertex{};
  MetaGraphVertices<Tail> verticesTail;
};

template<>
class MetaGraphVertices<typelist::NullType> {};

template<>
class MetaGraphVertices<typelist::EmptyTypeList> {};

template<size_t idx>
struct AdjacencyMatrixGraphVerticesGet
{
  template<typename VerticesStorage>
  static decltype(auto) Get (VerticesStorage &verticesStorage)
  {
    return AdjacencyMatrixGraphVerticesGet<idx - 1>
      ::Get(verticesStorage.verticesTail);
  }
};

template<>
struct AdjacencyMatrixGraphVerticesGet<0>
{
  template<typename VerticesStorage>
  static std::unique_ptr<typename VerticesStorage::Head> &Get (VerticesStorage &verticesStorage)
  {
    return verticesStorage.upVertex;
  }
};

template<size_t idx>
struct AdjacencyMatrixGraphVerticesSet
{
  template<typename T, typename VerticesStorage>
  static void Set (VerticesStorage &verticesStorage, T &&obj)
  {
    AdjacencyMatrixGraphVerticesSet<idx - 1>
      ::Set(verticesStorage.verticesTail, std::forward<T>(obj));
  }
};

template<>
struct AdjacencyMatrixGraphVerticesSet<0>
{
  template<typename T, typename VerticesStorage>
  static void Set (VerticesStorage &verticesStorage, T &&obj)
  {
    verticesStorage.upVertex = std::make_unique<typename VerticesStorage::Head>(obj);
  }
};
#endif //HW3_METAGRAPHVERTICES_H
