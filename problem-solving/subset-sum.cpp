/*
 * Given a set of non-negative integers, and a value sum, determine if there is 
 * a subset of the given set with sum equal to given sum.
 *
 * Source: https://www.geeksforgeeks.org/subset-sum-problem-dp-25.
 * */

#include <cstdio>
#include <vector>

using namespace std;

vector<int> set;
vector<vector<int>> c;

int n;

int s(int sum, int i) {
    if (sum == 0) return 1;
    if (sum < 0) return 0;
    if (i == n) return 0;

    if (c[sum][i] != -1) return c[sum][i];

    int a = s(sum - set[i], i + 1);
    int b = s(sum, i + 1);

    return c[sum][i] = max(a, b);
}

int main() {

    int sum, v;
    scanf(" %d %d", &n, &sum);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v);
        set.push_back(v);
    }
    c.assign(sum+1, vector<int>(n, -1));

    printf(" %d\n", s(sum, 0));

    return 0;
}
