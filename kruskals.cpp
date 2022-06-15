#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "Graphs.h"

// ensure vertices are not in the same set
// usually would employ Union-Find data structure
bool inSameSet(int v, int w, std::vector<std::set<int>>& eqClasses) {
    for (auto set : eqClasses) {
        if (set.find(v) != set.end() & set.find(w) != set.end()) {
            return true;
        }
    }

    return false;
}

void WeightedUndirectedGraph::kruskals() {
    std::vector<std::set<int>> eqClasses(numNodes);
    int sum = 0;

    // populate each equivalence class
    for (int i = 0; i < numNodes; ++i) {
        eqClasses[i].insert(i);
    }

    // sort edges
    std::sort(edgeList.begin(), edgeList.end(), [](auto a, auto b) {
        return a[2] < b[2];
    });

    for (auto edge : edgeList) {
        if (!inSameSet(edge[0], edge[1], eqClasses)) {
            sum += edge[2];
            int v = -1, w = -1;

            // find and union sets
            for (int i = 0; i < numNodes; ++i) {
                if (eqClasses[i].find(edge[0]) != eqClasses[i].end()) {
                    v = i;
                } else if (eqClasses[i].find(edge[1]) != eqClasses[i].end()) {
                    w = i;
                } else if (v != -1 && w != -1) {
                    break;
                }
            }

            eqClasses[v].insert(eqClasses[w].begin(), eqClasses[w].end());
            eqClasses[w].erase(eqClasses[w].begin(), eqClasses[w].end());
        }
    }

    std::cout << "MST: " << sum << std::endl;
}

int main() {
    WeightedUndirectedGraph g;
    g.kruskals(); // O(Vlog(E)) with Union-Find

    return 0;
}
