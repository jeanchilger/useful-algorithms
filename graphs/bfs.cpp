#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

// HERE
vector<vector<int> > paths; //[distance, predecessor]
vector<vector<int> > graph;
queue<int> buffer;

void bfs() {
    int dist;
    while (!buffer.empty()) {
        int vertex = buffer.front();

        dist = paths[vertex][0] + 1;

        for (int v : graph[vertex]) {
            if (paths[v][0] == -1) {
                buffer.push(v);
                paths[v][0] = dist;
                paths[v][1] = vertex;
            }

        }

        buffer.pop();
    }
}

int main() {

    int n;
    int v, e;
    int v0, v1;

    scanf("%d", &n);

    for (int cases = 1; cases <= n; cases++) {

        scanf(" %d %d", &v, &e);

        graph.assign(v, vector<int>());
        paths.assign(v, vector<int>(2, -1));

        for (int i = 0; i < e; i++) {
            scanf(" %d %d", &v0, &v1);

            graph[v0].push_back(v1);
            graph[v1].push_back(v0);

        }

        paths[0][0] = 0;
        buffer.push(0);

        bfs();

        for (int i = 0; i < v; i++) {
            printf("Vertex %d: %d\n", i, paths[i][0]); //print distance from source
        }




    }
    return 0;
}
