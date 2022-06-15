#include <iostream>
#include "Graph.h"

void Graph::dfs(int v) {
    if (!visited[v]) {
        // visit node
        visited[v] = true;
        std::cout << v << " ";

        // recurse for each neighbor
        for (int w : adj[v]) {
            dfs(w);
        }
    }
}

int main() {
    Graph g;
    g.dfs(1); // O(V + E)

    return 0;
}
