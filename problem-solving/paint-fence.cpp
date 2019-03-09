/*
 * Painting the Fence.
 *
 * Given a fence with n posts and k colors, find out the number of ways of painting the 
 * fence such that at most 2 adjacent posts have the same color. 
 * Since answer can be large return it modulo 10^9 + 7.
 *
 * Source: https://practice.geeksforgeeks.org/problems/painting-the-fence/0
 * */

#include <cstdio>
#include <vector>

#define m 1000000007

using namespace std;

vector<long int> cache;

long int s(long int n, long int k) {
    if (cache[n-1] != -1) return cache[n-1];
    if (n == 1) return cache[n-1] = k;
    if (n == 2) return cache[n-1] = k * (k - 1) + k;

    return cache[n-1] = (((k - 1) % m) * ((((s(n - 1, k) % m) + (s(n - 2, k)) % m) % m) % m) % m);
}

int main() {

    long int t, n, k;

    scanf(" %ld", &t);
    for (long int i = 0; i < t; i++) {
        
        scanf(" %ld %ld", &n, &k);
        cache.assign(n, -1);

        printf("%ld\n", s(n, k));
    }

    return 0;
}
