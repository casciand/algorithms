#ifndef GRAPH_H
#define GRAPH_H


#include <map>
#include <list>
#include <vector>

// dfs, bfs, scc, articulation points, prims & kruskals (with and without heap)
// general: greedy, dynamic programming, sorting

class UnweightedDirectedGraph {
private:
    std::map<int, std::list<int>> adj;
    std::map<int, bool> visited;

public:
    UnweightedDirectedGraph();

    void addEdge(int v, int w);
    void dfs(int v);
    void bfs(int v);
};

class WeightedUndirectedGraph {
private:
    std::vector<std::vector<int>> adj;
    int numNodes;

public:
    WeightedUndirectedGraph();

    void addEdge(int v, int w, int weight);
    void prims();
};

UnweightedDirectedGraph::UnweightedDirectedGraph() {
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

void UnweightedDirectedGraph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

WeightedUndirectedGraph::WeightedUndirectedGraph() {
    adj = { { 0, 2, 0, 6, 0 },
            { 2, 0, 3, 8, 5 },
            { 0, 3, 0, 0, 7 },
            { 6, 8, 0, 0, 9 },
            { 0, 5, 7, 9, 0 } };
    numNodes = 5;
}

void WeightedUndirectedGraph::addEdge(int v, int w, int weight) {
    adj[v][w] = weight;
    adj[w][v] = weight;
}


#endif //GRAPH_H
