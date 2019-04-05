#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// To change the type of the data
typedef int type;
typedef vector<type> vt;
typedef tuple<type, type> ii;

vector<vector<type>> graph; // graph as an adjacency list
vt parent, ranks;

void makeSet() {
    /*
     * Builds the Disjoin-Set data structure.
     * Uses a vector to store parents and another to store the ranks.
     * */

    type n = graph.size();
    for (type i = 0; i < n; i++) {
        parent[i] = i;
    }
}

type findSet(type x) {
    /*
     * Returns the representative of x's set.
     * */

    if (x != parent[x]) {
        parent[x] = findSet(parent[x]);
    }

    return parent[x];
}

bool sameSet(type x, type y) {
    /*
     * Returns whether or not x and y belongs to the same set.
     * */

    return findSet(x) == findSet(y);
}

void unionSet(type x, type y) {
    /*
     * Join the sets that x and y belongs.
     * */

    if (sameSet(x, y)) return;

    type xp = findSet(x);
    type yp = findSet(y);

    if (ranks[xp] > ranks[yp]) {
        // y.parent = x.parent
        parent[yp] = xp;

    } else {
        parent[xp] = yp;

        if (ranks[xp] == ranks[yp]) {
            ranks[yp] += 1;
        }
    }
}

void showMenu() {
    cout << "\n\t\t  MENU\n"
         << "================================================\n"
         << " | 1  -                                        |\n"
         << " | 2  - Search value                           |\n"
         << " | 3  - Erase element                          |\n"
         << " | 4  - Prints elements                        |\n"

    /*printf(" | 5  - Clean list                             |\n");
    printf(" | 6  - Calc. tree height                      |\n");
    printf(" | 7  - Number of nodes                        |\n");
    printf(" | 8  - Get predecessor                        |\n");
    printf(" | 9  - Get sucessor                           |\n");
    printf(" | 10 - Show menu                              |\n");
    printf(" | 0  - Exit                                   |\n");*/
         << "================================================\n";
}

void print(int v) {
    /*
     * Utility to print the graph.
     * */

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << i << " -> " << graph[i][j] << endl;
        }
        cout << endl;
    }

}

int main() {

    type v, e; // number of vertices and edges
    type i, j; // edge description (i -> j)

    // test
    type o, a, b;
    
    cin >> v >> e;

    graph.assign(v, vector<type>());
    parent.assign(v, 0);
    ranks.assign(v, 0);

    makeSet();

    for (int t = 0; t < e; t++) {
        cin >> i >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
        unionSet(i, j);
    }

    cout << sameSet(1, 2) << sameSet(0, 1) << sameSet(0, 2) << sameSet(3, 4) << sameSet(4, 1) << endl;
    for (int t=0; t < v; t++) {
        cout << ranks[t] << " ";
    }
    cout << endl;
        

    return 0;
}
