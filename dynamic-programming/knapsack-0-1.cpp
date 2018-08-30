// Using memoization
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int> > cache;
vector<int> values; // vector with the values of the items;
vector<int> weights; // vector with the weights of the items
int tw; // total weight of the knapsack
int n; // number of items;

int solve (int i, int w) { // i == item (peso, valor); w == soma total (0 - tw);
    /*
    Returns the biggest value that fits in a knapsack weight limit.
    */
    if (i == 0 || w == 0) return 0;

    if (cache[i][w] != -999) return cache[i][w];

    if (weights[i] > w) {
        return cache[i][w] = solve(i - 1, w);

    } else {
        int a = values[i] + solve(i - 1, w - weights[i]); // put current item
        int b = solve(i - 1, w); // dont put current item

        return cache[i][w] = max(a, b);

    }
}

int main () {

    cout << "Capacidade da Mochila: ";
    cin >> tw;

    cout << "Número de itens: ";
    cin >> n;

    cache.assign(n, vector<int> (tw+1, -999));

    int val, wei; // temporary variables;

    cout << "Descrição dos itens (peso valor)\n";
    for (int i = 0; i < n; i++) {
        cin >> wei >> val;
        weights.push_back(wei);
        values.push_back(val);
        cache[i][0] = 0;
    }

    for (int w = 0; w < tw; w++) {
        cache[0][w] = values[0];
    }
    int g = solve(n-1, tw);

    cout << g << "\n";

    return 0;
}
