// Using memoization
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int> > cache;
int tw; // total weight of the knapsack
vector<int> values; // vector with the values of the items;
vector<int> weights; // vector with the weights of the items
int n; // number of items;

int solve (int i, int w) { // i == item (peso, valor); w == soma total (0 - tw);
    /*
    Returns the biggest value that fits in a knapsack weight limit.
    */
    if (i == -1 || w == 0) return 0;

    if (cache[i][w] != -999) return cache[i][w];

    if (weights[i] > w) {
        return cache[i][w] = solve(i - 1, w);

    } else {
       /* return cache[i][w] = max(solve(i - 1, w),
                                 solve(i - 1, w - weights[i]) + values[i]); // knapsack 0/1*/
        return cache[i][w] = max(solve(i - 1, w),
                                 solve(i, w - weights[i]) + values[i]); // unbounded knapsack
    }

}

int main () {

    cout << "Capacidade da Mochila: ";
    cin >> tw;

    cout << "Número de itens: ";
    cin >> n;

    cache.assign(n, vector<int> (tw+1, -999));

    int val, wei; // temporary variables;

    cout << "Descrição dos itens (valor peso)\n";
    for (int i = 0; i < n; i++) {
        cin >> val >> wei;
        weights.push_back(wei);
        values.push_back(val);
    }

    int g = solve(n-1, tw);

    cout << g << "\n";

    return 0;
}
