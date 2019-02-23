/* 
 * Longest Palindromic Subsequence.
 * */

#include <iostream>
#include <string>

using namespace std;

long int lps(string s) {
    /*
     * Returns the size of the Longest Palindromic Subsequence
     * of a given string s.
     * */

    // Bottom-Up solution
    // Fills the table from northwest to southeast

    long int n = s.length();
    long int m[n][n];

    for (long int i = 0; i < n; i++) {
        m[i][i] = 1;
        for (long int j = 0; j < i; j++) {
            m[i][j] = 0;
        }
    }

    for (long int r = 2; r <= n; r++) {
        long int k = n - r + 1; // max line for i
        for (int i = 0; i < k; i++) {
            long int j = i + r - 1;
            if (s[i] == s[j]) {
                m[i][j] = m[i+1][j-1] += 2;
            } else {
                m[i][j] = max(m[i+1][j], m[i][j-1]);
            }
        }
    }

    return m[0][n-1];

}

int main() {

    string s;
    cout << "String: ";
    cin >> s;

    cout << "LPS size is: "
         << lps(s) << endl;

    return 0;
}
