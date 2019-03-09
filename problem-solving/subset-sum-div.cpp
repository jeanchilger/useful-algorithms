/*
 * Subset with Sum Divisible by m
 *
 * Given a set of non-negative distinct integers, and a value m, determine if there 
 * is a subset of the given set with sum divisible by m.
 *
 * Source: https://practice.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m/0
 * */

#include <cstdio>

using namespace std;

int s(int *arr, int n, int m) {
    /*AAAAAAAAAAAAAAAAa*/

    return 0;
}

int main() {

    int t, n, m;
    scanf(" %d", &t);
    
    for (int x = 0; x < t; x++) {
        scanf(" %d %d", &n, &m);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf(" %d", &arr[i]);
        }

        printf("%d\n", s(arr, n, m));
    }

    return 0;
}
