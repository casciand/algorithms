#include <iostream>
#include <queue>
#include "Graphs.h"

void UnweightedDirectedGraph::bfs(int v) {
    std::queue<int> q;
    q.push(v);

    while (!q.empty()) {
        // visit node
        v = q.front();
        std::cout << v << " ";
        visited[v] = true;
        q.pop();

        // add neighbors to queue
        for (int w : adjList[v]) {
            if (!visited[w]) {
                q.push(w);
            }
        }
    }
}

int main() {
    UnweightedDirectedGraph g;
    g.bfs(1); // O(V + E)

    return 0;
}
