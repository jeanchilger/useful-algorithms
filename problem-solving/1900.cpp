#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;
typedef long long int lli;

int main () {
    map<lli, lli> seq;

    int n;

    lli c = 0, vi, e = 0;

    scanf("%d", &n);
    seq[0] = 0;

    for (int i = 0; i < n; i++) {
        scanf(" %lli", &vi);
        
        e += vi;

        if (seq.find(e) != seq.end()) {
            seq[e] += 1;
            c += seq[e];
 
        } else {
            seq[e] = 0;
        }
    }
    
    printf("%lli\n", c);

    return 0;
}

