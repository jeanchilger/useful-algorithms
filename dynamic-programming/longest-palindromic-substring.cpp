/* 
 * Longest Palindromic Substring.
 * */

#include <iostream>
#include <string>

using namespace std;

void printSubstring(string s, long int i, long int j) {
    /*
     * Utility funciton to print a substring of 's' form 'i' to 'j'.
     * */

    for (int n = i; n <= j; n++) {
        cout << s[n];
    }
    cout << endl;
}

long int lps(string s) {
    /*
     * Returns the size of the Longest Palindromic Substring
     * of a given string 's'.
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

    long int bigger, start, end;

    for (long int r = 2; r <= n; r++) {
        long int k = n - r + 1; // max line for i
        for (int i = 0; i < k; i++) {
            long int j = i + r - 1;
            if (s[i] == s[j]) {
                m[i][j] = m[i+1][j-1] + 2;
                if (m[i][j] > bigger) {
                    bigger = m[i][j];
                    start = i;
                    end = j;
                }

            } else {
                m[i][j] = 1;     
            }
        }
    }

    printSubstring(s, start, end);
    return bigger;

}

int main() {

    string s;
    cout << "String: ";
    cin >> s;

    cout << "LPS is: ";
    cout << "LPS size is: "
         << lps(s) << endl;

    return 0;
}
