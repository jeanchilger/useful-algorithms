#include <cstdio>
#include <vector>

using namespace std;

int main () {

    int n;
    scanf("%d", &n);

    vector<vector<int> > t(n+1, vector<int>(n+2, 0));

    t[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=i+1; j++) {
            t[i][j] = t[i-1][j-1] + t[i-1][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n+1; j++) {
            printf("%9d", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
