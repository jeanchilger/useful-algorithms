/*
 * Gold Mine Problem
 *
 * Given a gold mine (M) of n*m dimensions. Each field in this mine contains a positive integer which is 
 * the amount of gold in tons. Initially the miner is at first column but can be at any row. 
 * He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the 
 * cell diagonally up towards the right or right or diagonally down towards the right. 
 * Find out maximum amount of gold he can collect.
 * 
 * Source: https://practice.geeksforgeeks.org/problems/gold-mine-problem/0
 * */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> M;

int solve(int n, int m) {
    int t[n+2][m+2];
    for (int i = 0; i < n+2; i++) {
        t[i][0] = 0;
        t[i][m+1] = 0;
    }

    for (int j = 0; j < m+2; j++) {
        t[0][j] = 0;
        t[n+1][j] = 0;
    }

    int res = 0;
    for (int j = 1; j < m+1; j++) {
        for (int i = 1; i < n+1; i++) {
            t[i][j] = max(t[i-1][j-1],
                          max(t[i][j-1],
                              t[i+1][j-1])) + M[i-1][j-1];
            if (t[i][j] > res) res = t[i][j];
        }
    }

    return res;
}

int main() {
    int n, m, t;
    cin >> t;

    for (int i=0; i < t; i++) {
        
        cin >> n >> m;
        M.assign(n, vector<int>(m, 0));
        
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> M[j][k];
            }
        }
        cout << solve(n, m) << endl;
    }

    return 0;
}

