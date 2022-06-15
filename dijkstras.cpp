#include <iostream>
#include <vector>
#include "Graphs.h"

int getSmallest(std::vector<int>& distances) {
    int smallest = INT32_MAX;
    int vertex = 0;

    for (int i = 0; i < distances.size(); ++i) {
        if (distances[i] < smallest && distances[i] > 0) {
            smallest = distances[i];
            vertex = i;
        }
    }

    return vertex;
}

void WeightedUndirectedGraph::dijkstras(int v) {
    std::vector<int> distances(numNodes, INT32_MAX);
    distances[v] = 0;

    // initialize distances from starting vertex
    for (int i = 0; i < numNodes; ++i) {
        if (adjMatrix[v][i] != 0) {
            distances[i] = adjMatrix[v][i];
        }
    }

    std::cout << "Distances to Vertex [" << v << "]" << std::endl << std::endl;

    // update distances for each new smallest distance vertex
    for (int i = 0; i < numNodes - 1; ++i) {
        int smallest = getSmallest(distances);
        std::cout << "Vertex [" << smallest << "]: " << distances[smallest] << std::endl;

        // update distances from the current smallest distance vertex
        for (int j = 0; j < numNodes; ++j) {
            if (distances[j] == INT32_MAX && adjMatrix[smallest][j] != 0) {
                distances[j] = distances[smallest] + adjMatrix[smallest][j];
            } else if (distances[j] > 0 && distances[j] < INT32_MAX && adjMatrix[smallest][j] != 0) {
                distances[j] = std::min(distances[j], distances[smallest] + adjMatrix[smallest][j]);
            }
        }

        distances[smallest] = 0; // visited
    }
}

int main() {
    WeightedUndirectedGraph g;
    g.dijkstras(1); // O(V^2)

    return 0;
}
