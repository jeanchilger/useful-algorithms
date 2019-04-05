/*
 * INPUT:
 *      1 -> Number of vertices and edges: v e
 *      2 -> e triple of numbers describing and edge (weight, start, end): w i j
 * */

#include <iostream>
#include <vector>
#include <tuple>

//#define edge(a, b, c) int* edge{a, b, c}

using namespace std;

// To change the type of the data
typedef int type;
typedef tuple<type, type> ii;

vector<vector<ii>> graph;

void print(int v) {
    /*
     * Utility to print the graph.
     * */

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << i << " -> " << get<0>(graph[i][j]) << ": " << get<1>(graph[i][j]) << endl;
        }
        cout << endl;
    }

}

int main() {

    int v, e; // number of vertices and edges
    int w, i, j; // weight, start and point of an edge

    cin >> v >> e;

    graph.assign(v, vector<ii>());

    for (int p = 0; p < e; p++) {
        cin >> w >> i >> j;
    
        ii x(j, w);
        graph[i].push_back(x);

        ii y(i, w);
        graph[j].push_back(y);
    }

    print(v);

    return 0;
}
