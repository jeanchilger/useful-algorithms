#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {

    int v, e, v0, v1;

    std::cout << "Number of vertices: ";
    std::cin >> v;
    std::cout << "Number of edges: ";
    std::cin >> e;


    std::vector<std::vector<int> > graph (v, std::vector<int>());

    for (int i = 0; i < e; i++) {
        std::cout << "Edge " << i << " (vertex, vertex): ";
        std::cin >> v0 >> v1;

        if (!(std::find(graph[v0].begin(), graph[v0].end(), v1) != graph[v0].end())) {
            // TODO: ADD A BINARY INSERTION TO THE GRAPH;
            graph[v0].push_back(v1);
            graph[v1].push_back(v0);
        }
    }

    return 0;
}
