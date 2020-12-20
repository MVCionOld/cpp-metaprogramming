#ifndef HW3_ADJACENCYMATRIXGRAPH_H
#define HW3_ADJACENCYMATRIXGRAPH_H

#include <memory>
#include "AdjacencyMatrixGraphEdges.h"
#include "../common/MetaGraphVertices.h"
#include "../common/TypeList/TypeList.h"

template<typename V, typename E>
struct AdjacencyMatrixGraph {};

template<typename ...TVertices, typename ...TEdges>
struct AdjacencyMatrixGraph<typelist::TypeList <TVertices...>, typelist::TypeList<TEdges...>>
{
  using Vertices = typename typelist::TypeList<TVertices...>;
  using Edges = typename typelist::TypeList<TEdges...>;

  static constexpr size_t nVertices = typelist::Length<Vertices>::val;
  static_assert(nVertices != 0, "NoVerticesException");

  AdjacencyMatrixGraph () :
      vertices(),
      edges()
  {}

  template<size_t idx>
  decltype(auto) GetVertex()
  {
    static_assert(
        0 <= idx && idx < nVertices,
        "Vertex index out of range"
    );
    return AdjacencyMatrixGraphVerticesGet<idx>
      ::Get(vertices);
  }

  template<size_t idx, typename T>
  void SetVertex(T&& obj)
  {
    static_assert(
        0 <= idx && idx < nVertices,
        "Vertex index out of range"
    );
    static_assert(
        std::is_same<
            typename std::remove_reference<T>::type,
            typename typelist::TypeAt<idx, Vertices>::res
        >::value,
        "Type mismatch with vertex type"
    );
    AdjacencyMatrixGraphVerticesSet<idx>
      ::Set(vertices, std::forward<T>(obj));
  }

  template<size_t srcId, size_t dstId>
  decltype(auto) GetEdge()
  {
    static_assert(
        0 <= srcId && srcId < nVertices,
        "Source vertex index out of range"
    );
    static_assert(
        0 <= dstId && dstId < nVertices,
        "Destination vertex index out of range"
    );
    return AdjacencyMatrixGraphEdgesGet<srcId, dstId>
      ::Get(edges);
  }

  template<size_t srcId, size_t dstId, typename T>
  void SetEdge(T&& obj)
  {
    static_assert(
        0 <= srcId && srcId < nVertices,
        "Source vertex index out of range"
    );
    static_assert(
        0 <= dstId && dstId < nVertices,
        "Destination vertex index out of range"
    );
    static_assert(
        std::is_same<
            typename std::remove_reference<T>::type,
            typename typelist::TypeAt<
                dstId,
                typename typelist::TypeAt<srcId, Edges>::res
            >::res
        >::value,
        "Type mismatch with edge type"
    );
    AdjacencyMatrixGraphEdgesSet<srcId, dstId>
      ::Set(edges, std::forward<T>(obj));
  }

  AdjacencyMatrixGraphEdges<Edges> edges;
  MetaGraphVertices<Vertices>      vertices;
};
#endif //HW3_ADJACENCYMATRIXGRAPH_H
