
# Домашнее задание №3

Вам необходимо реализовать **С++** библиотеку, позволяющую работать с графами.
В качестве вершин и весов рёбер графа могут выступать абсолютно разные сущности -- начиная от обычных чисел и заканчивая большими программными модулями (указатель на интерфейс которых вам будет передаваться)

Стандартные возможности такой библиотеки:  
*  Создание графа в виде матрицы смежности, списка смежности  
*  Итерация по вершинам с выполнением некоторого действия  
*  Реализация паттернов “Посетитель”, “Компоновщик”, “Цепочка ответственностей” на основе такого графа  
*  Генерация структуры графа на этапе компиляции (например, для графа сервисов в системе)

Остальные возможности остаются за вами, чем более гибкими они будут -- тем лучше.
Любое нарушение типовой безопасности и ограничений на параметры должно выводить для пользователя описание ошибки.

---

# Реализация

В рамках этого задания было реализовано создание графа в виде матрицы смежности и списков смежности c генерацией 
структуры графа на. Пример:  
для списков смежности:
```c++
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

    std::cout << "Vertex[id = 0] = " << *adjacencyListGraph.GetVertex<0>() << std::endl;  // Vertex[id = 0] = class A
```
для матрицы смежности:
```c++
    AdjacencyMatrixGraph<
        /*TVertices   = */TypeList<A, float, double, B>,
        /*TEdgesLists = */TypeList<
            TypeList<AbsentEdge, int,        int,         AbsentEdge>,
            TypeList<int,        AbsentEdge, std::string, AbsentEdge>,
            TypeList<int,        float,      AbsentEdge,  AbsentEdge>,
            TypeList<C,          AbsentEdge, AbsentEdge,  AbsentEdge>
        >
    > adjacencyMatrixGraph;

    adjacencyMatrixGraph.SetEdge<0, 1>((int) 0);
    adjacencyMatrixGraph.SetEdge<2, 1>((float) 42.1);
    adjacencyMatrixGraph.SetEdge<3, 0>(C());
    
    std::cout << "Edge[from=3, to=0] = " << *adjacencyMatrixGraph.GetEdge<3, 0>() << std::endl;  // Edge[from=3, to=0] = class C
```

### Ограничения

Передаваемые типы для вершин и ребер **обязаны** иметь конструктор по-умолчанию и перемещения.  
При задании графа в виде списков смежности, важно, чтобы присутствовал список смежности для каждой вершины вне 
зависимости от того, будет ли о пуст или нет. Список смежности задается в виде 
`AdjacentEdgesList<srcId, TypeList<AdjacentEdge<dstId, EdgeType>, ...> >>`, где:
*  `AdjacentEdgesList` -- тип, описывающий все смежные ребра для вершины с порядковым номером `srcId`;
*  `AdjacentEdge<dstId, EdgeType>` -- смежное ребро, где `srcId` -- начало, `dstId` -- конец, `EdgeType` -- тип ребра.  

При задании графа в виде матрицы смежности, размер матрицы должен совпадать с количеством вершин графа. В случае 
отсутствия ребра, можно воспользовать встроенным типом `AbsentEdge`.

### Что не доделано

Не реализованы: обход по вершинам с side-эффектом, а также паттерны, предложены выше.


