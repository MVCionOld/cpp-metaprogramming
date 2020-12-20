#ifndef HW3_ADJACENCYMATRIXGRAPHEDGES_H
#define HW3_ADJACENCYMATRIXGRAPHEDGES_H

#include "../common/MetaGraphVertices.h"
#include "../common/TypeList/TypeList.h"

template<class TEdges>
struct AdjacencyMatrixGraphEdges;

template<size_t srcId, size_t dstId>
struct AdjacencyMatrixGraphEdgesGet;

template<size_t srcId, size_t dstId>
struct AdjacencyMatrixGraphEdgesSet;

template<typename ...E>
struct AdjacencyMatrixGraphEdges<typelist::TypeList < E...>>
{
  AdjacencyMatrixGraphEdges () = default;

  MetaGraphVertices<typename typelist::TypeList<E...>::Head>         edgesHead; // ~ edge attr as vertex
  AdjacencyMatrixGraphEdges<typename typelist::TypeList<E...>::Tail> edgesTail;
};

template<>
struct AdjacencyMatrixGraphEdges<typelist::EmptyTypeList> {};

template<>
struct AdjacencyMatrixGraphEdges<typelist::NullType> {};

template<size_t srcId, size_t dstId>
struct AdjacencyMatrixGraphEdgesGet
{
  template<typename EdgesStorage>
  static decltype(auto) Get (EdgesStorage &edgesStorage)
  {
    return AdjacencyMatrixGraphEdgesGet<srcId - 1, dstId>
      ::Get(edgesStorage.edgesTail);
  }
};

template<size_t dstId>
struct AdjacencyMatrixGraphEdgesGet<0, dstId>
{
  template<typename EdgesStorage>
  static decltype(auto) Get (EdgesStorage &edgesStorage)
  {
    return AdjacencyMatrixGraphVerticesGet<dstId>
      ::Get(edgesStorage.edgesHead);
  }
};

template<size_t srcId, size_t dstId>
struct AdjacencyMatrixGraphEdgesSet
{
  template<typename T, typename EdgesStorage>
  static void Set (EdgesStorage &edgesStorage, T &&obj)
  {
    AdjacencyMatrixGraphEdgesSet<srcId - 1, dstId>
      ::Set(edgesStorage.edgesTail, std::forward<T>(obj));
  }
};

template<size_t dstId>
struct AdjacencyMatrixGraphEdgesSet<0, dstId>
{
  template<typename T, typename EdgesStorage>
  static void Set (EdgesStorage &edgesStorage, T &&obj)
  {
    AdjacencyMatrixGraphVerticesSet<dstId>
      ::Set(edgesStorage.edgesHead, std::forward<T>(obj));
  }
};
#endif //HW3_ADJACENCYMATRIXGRAPHEDGES_H
