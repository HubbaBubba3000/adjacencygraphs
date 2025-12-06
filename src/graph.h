#pragma once

#include <vector>

struct Edge {
  int Begin;
  int End;
};

Edge NewEdge(int begin, int end);

class Graph{
public:
    std::vector<int> V;
    std::vector<Edge> E;
    Graph(int vertex_count);
    void AddVertex(int v);
    void AddEdge(int b, int e);
    bool IsAdjacent(int v1, int v2);
};

Graph BuildGraph(std::vector<int>& ajm);
std::vector<int> DFS(Graph& G, int startvertex);
