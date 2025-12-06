#include "graph.h"
#include <stack>
#include <vector>

Edge NewEdge(int begin, int end) {
    Edge e;
    e.Begin = begin;
    e.End = end;
    return e;
}
Graph::Graph(int vertex_count) {
    V.reserve(vertex_count);
    // E.reserve(vertex_count-1);
}

bool Graph::IsAdjacent(int v1, int v2) {
    for (Edge& e : E) {
        return true && e.Begin == v1 && e.End == v2;
    }
    return false;
}

void Graph::AddVertex(int v) {
    V.push_back(v);
}
void Graph::AddEdge(int b, int e) {
    E.push_back(NewEdge(b,e));
}

Graph BuildGraph(std::vector<int>& ajm) {
    Graph G(ajm.size());
    for (int i=0; i <= ajm.size();i++) {
        G.AddVertex(i);
        for (int j=ajm.size()-1;j>=0;j--) {
            bool bit = (i >> j) & 1;
            if (bit == 1) {
                G.AddEdge(i, j);
            }
        }
    }
    return G;
}

//поиск в глубину
std::vector<int> DFS(Graph& G, int start) {
    std::vector<int> order;
    std::vector<short> visited(G.V.size());
    std::stack<int> stack;

    visited[start] = true;
    stack.push(start);
    order.emplace_back(start+1);

    while (!stack.empty()) {
        auto from = stack.top();
        bool is_found = false;
        for (int to = 0, size = G.V.size(); to != size;++to) {
            if (!visited[to] && G.IsAdjacent(from, to)) {
                is_found = true;
                visited[to] = true;
                stack.push(to);
                order.emplace_back(to+1);
                from = to;
            }
        }
        if (!is_found) {
            stack.pop();
        }
    }
    return order;
}
// проход всех компонентов связности графа
std::vector<int> DFSAll(Graph& G) {
    int n = G.V.size();
    std::vector<short> visited(n);
    std::vector<int> order;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            for (int v : DFS(G, visited[i])) {
                order.emplace_back(v);
            }
        }
    }
    return order;
}
