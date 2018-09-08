#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > cache;
string a, b;

int lcs1 (int pa, int pb) {
    /*
     * Returns the longest common (contiguous) subsequence between two strings 'a' and 'b'.
     * 'pa' and 'pb' are the length of strings 'a' and 'b' respectively.
     *  - EX: lcs of 'abcd' and 'axbcyd' is 2.
    */

    int currBiggest = -999; // current lcs
    for (int i = 0; i < pa; i++) {
        for (int j = 0; j < pb; j++) {
            if (a[i] == b[j]) {
                cache[i+1][j+1] = 1 + cache[i][j];

            } else {
                cache[i+1][j+1] = 0;
            }

            if (cache[i+1][j+1] > currBiggest) {
                currBiggest = cache[i+1][j+1];
            }
        }
    }
    return currBiggest;
}

int lcs2 (int pa, int pb) {
    /*
     * Returns the longest common subsequence between two strings 'a' and 'b'.
     * 'pa' and 'pb' are the length of strings 'a' and 'b' respectively.
     * This lcs ignores considers relative same position of strings.
     *  - EX: lcs of 'abcd' and 'axbcyd' is 4;
    */

    for (int i = 0; i < pa; i++) {
        for (int j = 0; j < pb; j++) {
            if (a[i] == b[j]) {
                cache[i+1][j+1] = 1 + cache[i][j];
                                                                  
            } else {
                 cache[i+1][j+1] = max(cache[i+1][j], cache[i][j+1]);                 
            }  
        }              
    }

    return cache[pa][pb];
}

int main () {
    
    cin >> a >> b;
    
    cache.assign(a.length()+1, vector<int>(b.length()+1, -1));
    cache[0].assign(b.length()+1, 0);

    for (int i = 0; i < (int)a.length(); i++) {
        cache[i][0] = 0;
    }

    cout << "lcs with contiguous subsequence " << lcs2((int)a.length(), (int)b.length()) << "\n";

    return 0;
}
