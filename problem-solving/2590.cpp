#include <cstdio>

using namespace std;

int main () {

    int t;
    long long n;
    
    scanf("%d", &t);

    int a[4] = {1, 7, 9, 3};

    for (int i = 0; i < t; i++) {
        scanf("%lli", &n);
        printf("%d\n", a[n%4]);
    }

    return 0;
}
