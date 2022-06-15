#include <iostream>
#include "Graph.h"

void WeightedUndirectedGraph::prims() {
    std::vector<int> distances(numNodes, INT32_MAX);
    distances[0] = -1; // avoid repeating back to start node
    int index = 0, sum = 0;

    for (int i = 0; i < numNodes - 1; ++i) {
        // update the smallest edge for each vertex
        for (int j = 0; j < numNodes; ++j) {
            if (adjMatrix[index][j] < distances[j] && adjMatrix[index][j] != 0) {
                distances[j] = adjMatrix[index][j];
            }
        }

        int smallest = INT32_MAX;

        // find the smallest current edge to add
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
