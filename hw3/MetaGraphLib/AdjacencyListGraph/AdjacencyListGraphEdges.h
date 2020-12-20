#ifndef HW3_ADJACENCYLISTGRAPHEDGES_H
#define HW3_ADJACENCYLISTGRAPHEDGES_H

#include "../common/MetaGraphVertices.h"
#include "../common/TypeList/TypeList.h"

template<size_t dstId_, typename TEdgeType>
struct AdjacentEdge
{
  static constexpr size_t dstId = dstId_;
  using EdgeType = TEdgeType;
};

template<size_t srcId_, typename TListType>
struct AdjacentEdgesList
{
  static constexpr size_t srcId = srcId_;
  using ListType = TListType;
};

template<class TEdges>
struct AdjacencyListGraphEdges;

template<size_t srcId, size_t dstId>
struct AdjacencyListGraphEdgesGet;

template<size_t srcId, size_t dstId>
struct AdjacencyListGraphEdgesSet;

template<typename ...E>
struct AdjacencyListGraphEdges<typelist::TypeList < E...>>
{
  AdjacencyListGraphEdges () = default;

  MetaGraphVertices<typename typelist::TypeList<E...>::Head>       edgesHead; // ~ edge attr as vertex
  AdjacencyListGraphEdges<typename typelist::TypeList<E...>::Tail> edgesTail;
};

template<>
struct AdjacencyListGraphEdges<typelist::EmptyTypeList> {};

template<>
struct AdjacencyListGraphEdges<typelist::NullType> {};

template<size_t srcId, size_t dstId>
struct AdjacencyListGraphEdgesGet
{
  template<typename AdjacentEdgesStorage>
  static decltype(auto) Get (AdjacentEdgesStorage &edgesStorage)
  {
    return AdjacencyListGraphEdgesGet<srcId - 1, dstId>
      ::Get(edgesStorage.edgesTail);
  }
};

template<size_t dstId, int steps = dstId>
struct AdjacencyListGraphEdgesGetHelper
{
  template<typename AdjacentEdgesStorage>
  static decltype(auto) Get (AdjacentEdgesStorage &edgesStorage)
  {
    return AdjacencyListGraphEdgesGetHelper<dstId, steps-1>
      ::Get(edgesStorage.edgesHead);
  }
};

template<size_t dstId>
struct AdjacencyListGraphEdgesGetHelper<dstId, 0>
{

};

template<size_t dstId>
struct AdjacencyListGraphEdgesGet<0, dstId>
{
  template<typename EdgesStorage>
  static decltype(auto) Get (EdgesStorage &edgesStorage)
  {
    return AdjacencyListGraphEdgesGetHelper<dstId>
       ::Get(edgesStorage.edgesHead);
  }
};

//template<size_t dstId, size_t currDstId>
//struct AdjacencyListGraphEdgesGetHelper
//{
//  template<typename EdgesStorage>
//  static decltype(auto) Get (EdgesStorage &edgesStorage)
//  {
//    return AdjacencyListGraphEdgesGetHelper<dstId>
//    ::Get(edgesStorage.edgesHead);
//  }
//};
//
//template<size_t dstId, size_t currDstId>
//struct AdjacencyListGraphEdgesGetHelper
//{
//  template<typename EdgesStorage>
//  static decltype(auto) Get (EdgesStorage &edgesStorage)
//  {
//    return AdjacencyListGraphVerticesGet<dstId>
//    ::Get(edgesStorage.edgesHead);
//  }
//};


//
//template<size_t srcId, size_t dstId>
//struct AdjacencyListGraphEdgesSet
//{
//  template<typename T, typename EdgesStorage>
//  static void Set (EdgesStorage &edgesStorage, T &&obj)
//  {
//    AdjacencyListGraphEdgesSet<srcId - 1, dstId>
//      ::Set(edgesStorage.edgesTail, std::forward<T>(obj));
//  }
//};
//
//template<size_t dstId>
//struct AdjacencyListGraphEdgesSet<0, dstId>
//{
//  template<typename T, typename EdgesStorage>
//  static void Set (EdgesStorage &edgesStorage, T &&obj)
//  {
//    AdjacencyListGraphVerticesSet<dstId>
//      ::Set(edgesStorage.edgesHead, std::forward<T>(obj));
//  }
//};

#endif //HW3_ADJACENCYLISTGRAPHEDGES_H
