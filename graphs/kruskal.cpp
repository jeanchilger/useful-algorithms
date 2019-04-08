#include <iostream>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

// To change the type of the data
typedef int type;
typedef vector<type> vt;
typedef tuple<type, type, type> iii;

vector<iii> graph; // graph as an edge list
vector<iii> mst; // Minimum Spanning Tree formed with Kruskal's algorithm
vt parent, ranks;

// Utility
//
int partition(int first, int last) {
    /*
     * returns the index of the pivot
     * before return, the pivot is set to its correct position
     * */
    
    int pivot = first;
    int low = first + 1;
    int high = last;
    int temp;
    
    while (low <= high) {
        if (get<0>(graph[low]) <= get<0>(graph[pivot])) {
            low++;

        } else {
            if (get<0>(graph[high]) >= get<0>(graph[pivot])) {
                high--;
                                                            
            } else {
                temp = get<0>(graph[low]);
                get<0>(graph[low]) = get<0>(graph[high]);
                get<0>(graph[high]) = temp;                                                                               
            }                    
        }
    }

    temp = get<0>(graph[pivot]);
    get<0>(graph[pivot]) = get<0>(graph[high]);
    get<0>(graph[high]) = temp;

    return high;
}

void quicksort(int first, int last) {
    /*
     * sorts an array in increasing order
     * */

    if (first < last) {
        int p = partition(first, last);
        
        quicksort(first, p - 1);
        quicksort(p + 1, last);                            
    }
}

// <<<< UNION FIND
//
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
//
// >>>>

void kruskal(type e) {
    /*
     * Performs the Kruskal's algorithm.
     * e -> number of edges.
     * */

    for (type i = 0; i < e; i++) {

    }

}

//void print(int v) {
    /*
     * Utility to print the graph.
     * */

/*    for (int i = 0; i < v; i++) {
         for (int j = 0; j < graph[i].size(); j++) {
             cout << i << " -> " << get<1>(graph[i][j]) << ": " << get<2>(graph[i][j]) << endl;
         }
         cout << endl;
     }

}*/

int main() {

    type v, e; // number of vertices and edges
    type w, i, j; // edge description (w i -> j)

    // test
    type o, a, b;
    
    cin >> v >> e;

    parent.assign(v, 0);
    ranks.assign(v, 0);

    makeSet();

    for (int t = 0; t < e; t++) {
        cin >> w >> i >> j;
        iii n(w, i, j);
        graph.push_back(n);
    }

    quicksort(0, graph.size()-1);

    for (int t = 0; t < e; t++) {
        cout << get<0>(graph[t]) << " : " << get<1>(graph[t]) << " -> " << get<2>(graph[t]) << endl;
    }

    return 0;
}
