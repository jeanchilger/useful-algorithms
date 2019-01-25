#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > cache;
vector<int> coins;

int v, m; // value to change | number of coins

int coin(int s, int i) { // value left to change, index

    if (s == 0) return 1;
    if (s < 0) return 0;
    if (i == m) return 0;
    if (cache[s][i] != -1) return cache[s][i];

    int a = coin(s - coins[i], i + 1);
    int b = coin(s, i + 1);


    return cache[s][i] = max(a, b);
}

int main () {

    int val;
    scanf("%d %d", &v, &m);

    cache.assign(v+1, vector<int> (m, -1));

    for (int i = 0; i < m; i++) {
        scanf(" %d", &val);
        coins.push_back(val);
    }
    
    printf("%d\n", coin(v, 0));

    return 0;
}
