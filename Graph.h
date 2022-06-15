#ifndef GRAPH_H
#define GRAPH_H


#include <map>
#include <list>

// dfs, bfs, scc, articulation points, prims & kruskals (with and without heap)
// general: greedy, dynamic programming, sorting

// defines a directed graph
class Graph {
private:
    std::map<int, std::list<int>> adj;
    std::map<int, bool> visited;

public:
    Graph();

    void addEdge(int v, int w);
    void dfs(int v);
    void bfs(int v);
};

Graph::Graph() {
    addEdge(0, 5);
    addEdge(1, 0);
    addEdge(1, 3);
    addEdge(2, 1);
    addEdge(3, 0);
    addEdge(3, 2);
    addEdge(4, 0);
    addEdge(4, 3);
    addEdge(5, 4);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}


#endif //GRAPH_H
