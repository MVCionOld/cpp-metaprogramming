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

#endif //HW3_ADJACENCYLISTGRAPHEDGES_H
