#ifndef GRAPH_H
#define GRAPH_H


#include <map>
#include <list>
#include <vector>

// dfs, bfs, scc, articulation points, dijkstras, prims & kruskals (with and without heap)
// general: greedy, dynamic programming, sorting

class UnweightedDirectedGraph {
private:
    std::map<int, std::list<int>> edgeList;
    std::map<int, bool> visited;

public:
    UnweightedDirectedGraph();

    void addEdge(int v, int w);
    void dfs(int v);
    void bfs(int v);
};

class WeightedUndirectedGraph {
private:
    std::vector<std::vector<int>> adjMatrix;
    std::vector<std::vector<int>> edgeList;
    int numNodes;

public:
    WeightedUndirectedGraph();

    void addEdge(int v, int w, int weight);
    void prims();
    void kruskals();
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
    edgeList[v].push_back(w);
}

WeightedUndirectedGraph::WeightedUndirectedGraph() {
    adjMatrix = {{ 0, 4,  0, 0,  0,  0,  0, 8,  0 },
                 { 4, 0,  8, 0,  0,  0,  0, 11, 0 },
                 { 0, 8,  0, 7,  0,  4,  0, 0,  2 },
                 { 0, 0,  7, 0,  9,  14, 0, 0,  0 },
                 { 0, 0,  0, 9,  0,  10, 0, 0,  0 },
                 { 0, 0,  4, 14, 10, 0,  2, 0,  0 },
                 { 0, 0,  0, 0,  0,  2,  0, 1,  6 },
                 { 8, 11, 0, 0,  0,  0,  1, 0,  7 },
                 { 0, 0,  2, 0,  0,  0,  6, 7,  0 }};
    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 7, 11);
    addEdge(1, 2, 8);
    addEdge(2, 3, 7);
    addEdge(2, 5, 4);
    addEdge(2, 8, 2);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);
    numNodes = 9;
}

void WeightedUndirectedGraph::addEdge(int v, int w, int weight) {
    edgeList.push_back({v, w, weight});
}


#endif //GRAPH_H
