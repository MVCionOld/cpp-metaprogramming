# cmake_minimum_required(VERSION <specify CMake version here>)
project(hw3)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        hw3
        main.cpp
        MetaGraphLib/common/AbsentEdge.h
        MetaGraphLib/AdjacencyMatrixGraph/AdjacencyMatrixGraph.h
        MetaGraphLib/AdjacencyListGraph/AdjacencyListGraph.h
        MetaGraphLib/common/TypeList/TypeList.h
        MetaGraphLib/AdjacencyMatrixGraph/AdjacencyMatrixGraphEdges.h
        MetaGraphLib/common/MetaGraphVertices.h
        MetaGraphLib/AdjacencyListGraph/AdjacencyListGraphEdges.h)
