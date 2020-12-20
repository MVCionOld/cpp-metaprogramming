#include <iostream>
#include "MetaGraphLib/common/AbsentEdge.h"
#include "MetaGraphLib/common/TypeList/TypeList.h"
#include "MetaGraphLib/AdjacencyListGraph/AdjacencyListGraph.h"
#include "MetaGraphLib/AdjacencyMatrixGraph/AdjacencyMatrixGraph.h"

using namespace typelist;

int main ()
{
  ////////////////////////////////////////////////////////////////////////////////////////////////
  {
    AdjacencyListGraph<
      /*TVertices   = */TypeList<int, float, double>,
      /*TEdgesLists = */TypeList<
        AdjacentEdgesList</*srcId=*/0, TypeList<AdjacentEdge<1, int>, AdjacentEdge<2, int>         >>,
        AdjacentEdgesList</*srcId=*/1, TypeList<AdjacentEdge<0, int>, AdjacentEdge<2, std::string> >>,
        AdjacentEdgesList</*srcId=*/2, TypeList<AdjacentEdge<0, int>, AdjacentEdge<1, float>       >>
      >
    > adjacencyListGraph;

    adjacencyListGraph.SetVertex<0>((int) 1);
    adjacencyListGraph.SetVertex<1>((float) 2.2f);
    adjacencyListGraph.SetVertex<2>((double) 4.0);

    std::cout << "Vertex[id = 2] = " << *adjacencyListGraph.GetVertex<1>()
              << std::endl;

  }
  ////////////////////////////////////////////////////////////////////////////////////////////////
  {
    AdjacencyMatrixGraph<
        /*TVertices   = */TypeList<int, float, double>,
        /*TEdgesLists = */TypeList<
            TypeList<AbsentEdge, int, int>,
            TypeList<int, AbsentEdge, std::string>,
            TypeList<int, float, AbsentEdge>
        >
    > adjacencyMatrixGraph;

    adjacencyMatrixGraph.SetVertex<0>((int) 1);
    adjacencyMatrixGraph.SetVertex<1>((float) 2.0f);
    adjacencyMatrixGraph.SetVertex<2>((double) 4.0);

    adjacencyMatrixGraph.SetEdge<0, 1>((int) 0);
    adjacencyMatrixGraph.SetEdge<1, 2>(std::string("Hello, World!"));
    adjacencyMatrixGraph.SetEdge<2, 1>((float) 42.1);

    std::cout << "Edge[from=0, to=1] = " << *adjacencyMatrixGraph.GetEdge<0, 1>()
              << std::endl
              << "Vertex[id = 2] = " << *adjacencyMatrixGraph.GetVertex<2>()
              << std::endl;
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////
  return 0;
}
