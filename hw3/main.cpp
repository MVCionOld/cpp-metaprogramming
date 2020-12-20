#include <iostream>
#include "Classes/Classes.h"
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
      /*TVertices   = */TypeList<A, float, double, B>,
      /*TEdgesLists = */TypeList<
        AdjacentEdgesList</*srcId=*/0, TypeList<AdjacentEdge<1, int>, AdjacentEdge<2, int>         >>,
        AdjacentEdgesList</*srcId=*/1, TypeList<AdjacentEdge<0, int>, AdjacentEdge<2, std::string> >>,
        AdjacentEdgesList</*srcId=*/2, TypeList<AdjacentEdge<0, int>, AdjacentEdge<1, float>       >>,
        AdjacentEdgesList</*srcId=*/3, TypeList<AdjacentEdge<0, C>                                 >>

      >
    > adjacencyListGraph;

    adjacencyListGraph.SetVertex<0>(A());
    adjacencyListGraph.SetVertex<1>((float) 2.2f);
    adjacencyListGraph.SetVertex<2>((double) 4.0);
    adjacencyListGraph.SetVertex<3>(B());

    std::cout << "Vertex[id = 0] = " << *adjacencyListGraph.GetVertex<0>()
              << std::endl;

  }
  ////////////////////////////////////////////////////////////////////////////////////////////////
  {
    AdjacencyMatrixGraph<
        /*TVertices   = */TypeList<A, float, double, B>,
        /*TEdgesLists = */TypeList<
            TypeList<AbsentEdge, int,        int,         AbsentEdge>,
            TypeList<int,        AbsentEdge, std::string, AbsentEdge>,
            TypeList<int,        float,      AbsentEdge,  AbsentEdge>,
            TypeList<C,          AbsentEdge, AbsentEdge,  AbsentEdge>
        >
    > adjacencyMatrixGraph;

    adjacencyMatrixGraph.SetVertex<0>(A());
    adjacencyMatrixGraph.SetVertex<1>((float) 2.0f);
    adjacencyMatrixGraph.SetVertex<2>((double) 4.0);
    adjacencyMatrixGraph.SetVertex<3>(B());

    adjacencyMatrixGraph.SetEdge<0, 1>((int) 0);
    adjacencyMatrixGraph.SetEdge<2, 1>((float) 42.1);
    adjacencyMatrixGraph.SetEdge<3, 0>(C());

    std::cout << "Edge[from=3, to=0] = " << *adjacencyMatrixGraph.GetEdge<3, 0>()
              << std::endl
              << "Vertex[id = 2] = " << *adjacencyMatrixGraph.GetVertex<2>()
              << std::endl;
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////
  return 0;
}
