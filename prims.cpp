#include <iostream>
#include "Graph.h"

void WeightedUndirectedGraph::prims() {
    std::vector<int> distances(numNodes, INT32_MAX);
    distances[0] = -1; // avoid repeating back to start node
    int index = 0, sum = 0;

    for (int i = 0; i < numNodes - 1; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            if (adj[index][j] < distances[j] && adj[index][j] != 0) {
                distances[j] = adj[index][j];
            }
        }

        int smallest = INT32_MAX;

        for (int j = 0; j < distances.size(); ++j) {
            if (distances[j] < smallest && distances[j] >= 0) {
                smallest = distances[j];
                index = j;
            }
        }

        sum += smallest;
        distances[index] = -1;
    }

    std::cout << "MST: " << sum << std::endl;
}

int main() {
    WeightedUndirectedGraph g;
    g.prims();

    return 0;
}
