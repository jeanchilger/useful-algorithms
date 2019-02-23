#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long int li;

li scs(string x, string y) {
    /*
     * Returns the Shortest Common Supersequence between
     * two strings x and y.
     * */

    li n = x.length(),
       m = y.length();

    li t[n+1][m+1];

    for (li i = 0; i <= n; i++) {
        t[i][0] = i;
    }

    for (li j = 0; j <= m; j++) {
        t[0][j] = j;
    }

    for (li i = 1; i <= n; i++) {
        for (li j = 1; j <= m; j++) {
            if (x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];

            else
                t[i][j] = 1 + min(t[i-1][j], t[i][j-1]);
        }
    }



    return t[n][m];

}

int main() {

    string x, y;

    cin >> x >> y;

    li n = x.length(), 
       m = y.length();

    cout << scs(x, y) << endl;

    return 0;
}
