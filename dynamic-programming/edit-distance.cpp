#include <iostream>
#include <vector>
#include <string>

typedef long int li;

using namespace std;

vector<vector<li >> cache;

string x, y;
int costs[3];

li ed (li n, li m) {
    /*
     * Returns the minimun edit distance to transform a string
     * x [i ... n] in a string y[j .. m].
     * */
    
    for (li i = 1; i <= n; i++) {
        for (li j = 1; j <= m; j++) {
            if (x[i-1] == y[j-1]) {
                cache[i][j] = cache[i-1][j-1];
            } else {
                cache[i][j] = 1 + min(cache[i-1][j],
                                      min(cache[i-1][j-1],
                                          cache[i][j-1]));
            }
        }
    }
   
    return cache[n][m];


    /*if (i <= 0)
        return j + 1;

    if (j <= 0)
        return i + 1;

    if (cache[i][j] != -1) 
        return cache[i][j];
    
    if (x[i] == y[j]) 
        return cache[i][j] = ed(i-1, j-1);
    
    else 
        return cache[i][j] = 1 + min(ed(i-1, j),
                                     min(ed(i-1, j-1),
                                         ed(i, j-1))
                                 );*/

}

int main() {

    /*cout << "Costs for Delete, Replace and Insert: ";
    cin >> costs[0] >> costs[1] >> costs[2];*/

    /*cout << "String x: ";
    cin >> x;

    cout << "String y: ";
    cin >> y;*/

    vector<string> xa = {"abcdefghijk", "geek", "sunday", "zvfrkmlnozjkpqpxrjxkitzyxacbhhkicqcoendtomfgdwdwfcgpxiqvk"};
    vector<string> ya = {"lmnopqrstuv", "gesek", "saturday", "uytdlcgdewhtaciohordtqkvwcsgspqoqmsboaguwnny"};

    for (int ss = 0; ss < 4; ss++){

        x = xa[ss];
        y = ya[ss];
        
        li n = x.length();
        li m = y.length();

        cache.assign(n + 1, vector<li>(m + 1));
        //cout << "NN: " << n << "MM:  " << m << endl;

        for (li i = 0; i < n+1; i++) {
            cache[i][0] = i;
        }

        for (li j = 0; j < m+1; j++) {
            cache[0][j] = j;
        }

        cout << "Edit distace is: " 
             << ed(n, m)
             << endl;
    }

    return 0;
}
