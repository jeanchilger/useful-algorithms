#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// HERE
int visited[64];

void dfs(vector<vector<int> > graph, int vertex, int compId) {

    visited[vertex] = 1;
    components[compId].push_back(vertex);
    for (int v = 0; v < graph[vertex].size(); v++) {
        if (!visited[graph[vertex][v]]) {
            dfs(graph, graph[vertex][v], compId);
        }
    }
}


int main() {

    int n;
    int v, e;
    char v0, v1;

    scanf("%d", &n);

    for (int cases = 1; cases <= n; cases++) {

        printf("Case #%d:\n", cases);

        scanf(" %d %d", &v, &e);

        // creates the graph
        vector<vector<int> > graph (v, vector<int>());
        memset(visited, 0, sizeof(visited)); //if 0: all 0, if -1: all 1;

        for (int i = 0; i < e; i++) {
            scanf(" %c %c", &v0, &v1);
            v0 -= 'a';
            v1 -= 'a';

            graph[v0].push_back(v1);
            graph[v1].push_back(v0);

        }


        dfs(graph, 0, 0);

        int id = 1;
        for (int i = 0; i < v; i++) {

            if (!visited[i]) {
                dfs(graph, i, id);
                id++;
            }
        }




    }
    return 0;
}
