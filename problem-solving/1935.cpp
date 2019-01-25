#include <cstdio>

using namespace std;

typedef unsigned long long llu;

int main () {

    llu b, n;
    llu l = 1;
    llu c = 1; // c-1

    llu p = 4 * (n-1);
    while (b > p) {
        b -= p;
        n -= 2;
        p = 4 * (n-1);
        l++, c++;
    }

    
    
    printf("%d %d\n", l, c-1);

    return 0;
}
