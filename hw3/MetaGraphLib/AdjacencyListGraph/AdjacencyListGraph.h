#ifndef HW3_ADJACENCYLISTGRAPH_H
#define HW3_ADJACENCYLISTGRAPH_H

#include <memory>
#include "AdjacencyListGraphEdges.h"
#include "../common/AbsentEdge.h"
#include "../common/MetaGraphVertices.h"
#include "../common/TypeList/TypeList.h"

template<typename V, typename E>
struct AdjacencyListGraph {};

template<typename ...TVertices, typename ...TAdjacencyEdgesLists>
class AdjacencyListGraph<typelist::TypeList <TVertices...>, typelist::TypeList<TAdjacencyEdgesLists...>>
{
public:
  using Vertices = typename typelist::TypeList<TVertices...>;
  using AdjacencyEdges = typename typelist::TypeList<TAdjacencyEdgesLists...>;

  static constexpr size_t nVertices = typelist::Length<Vertices>::val;
  static_assert(nVertices != 0, "NoVerticesException");

  AdjacencyListGraph () :
      vertices()
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

private:
  MetaGraphVertices<Vertices>             vertices;
};
#endif //HW3_ADJACENCYLISTGRAPH_H
