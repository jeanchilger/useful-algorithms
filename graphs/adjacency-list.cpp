#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t, v, e;
    int va, vb;
    cin >> t;

    for (int i = 0; i < t; i++) {

        cin >> v >> e;
        vector<int> adj[v];
        for (int vi = 0; vi < e; vi++) {
            cin >> va >> vb;
            adj[va].push_back(vb);
            adj[vb].push_back(va);
        }

        for (int i = 0; i < v; i++) {
            cout << i;
            for (int j = 0; j < v; j++) {   
                cout << "-> " << adj[i][j];
            }
            cout << endl;
        }
    }




    return 0;
}
