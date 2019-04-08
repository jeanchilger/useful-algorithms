/*
 * Subset with Sum Divisible by m
 *
 * Given a set of non-negative distinct integers, and a value m, determine if there 
 * is a subset of the given set with sum divisible by m.
 *
 * Source: https://practice.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m/0
 * */

// This solution is incomplete, is needed to add memoization.

#include <cstdio>
#include <vector>

using namespace std;

int n, m;

vector<vector<int>> c;
vector<int> set;

int s(int i, int sum) {
    if (sum % m == 0 && sum != 0) return 1;
    if (i > n) return 0; 
    
    int a = s(i + 1, sum + set[i]);
    int b = s(i + 1, sum);

    return max(a, b);
}

int main() {

    int t, v;
    scanf(" %d", &t);
    
    for (int x = 0; x < t; x++) {
        scanf(" %d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            scanf(" %d", &v);
            set.push_back(v);
        }

        printf("%d\n", s(0, 0));
    }

    return 0;
}
