#include <iostream>
#include "Graphs.h"

void UnweightedDirectedGraph::dfs(int v) {
    if (!visited[v]) {
        // visit node
        visited[v] = true;
        std::cout << v << " ";

        // recurse for each neighbor
        for (int w : adjList[v]) {
            dfs(w);
        }
    }
}

int main() {
    UnweightedDirectedGraph g;
    g.dfs(1); // O(V + E)

    return 0;
}
