// Use bottom-up approach
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int> > cache;
vector<int> values; // vector with the values of the items;
vector<int> weights; // vector with the weights of the items

int solve (int n, int tw) { // i == item (peso, valor); w == soma total (0 - tw);
    /*
    Returns the biggest value that fits in a knapsack weight limit.
    */
    for (int i = 0; i < n+1; i++) { // items (i -- n-1)
        for (int w = 0; w < tw+1; w++) { // weights (0 -- tw)
            if (i == 0 || w == 0) {
                cache[i][w] = 0; // first row all zeros (avoid erros)

            } else {

                if (weights[i-1] > w) {
                    cache[i][w] = cache[i-1][w];
                } else {
                    cache[i][w] = max(values[i -1] + cache[i-1][w - weights[i -1]],
                                      cache[i-1][w]);
                }
            }
        }
    }

    return cache[n][tw];
}

int main () {
    int tw; // total weight of the knapsack
    int n; // number of items;

    cout << "Capacidade da Mochila: ";
    cin >> tw;

    cout << "Número de itens: ";
    cin >> n;

    cache.assign(n+1, vector<int> (tw+1, -999));

    int val, wei; // temporary variables;

    cout << "Descrição dos itens (peso valor)\n";
    for (int i = 0; i < n; i++) {
        cin >> val >> wei;
        weights.push_back(wei);
        values.push_back(val);
        cache[i][0] = 0; // first column all zeros;
    }

    int g = solve(n, tw);

    cout << g << "\n";

    return 0;
}
