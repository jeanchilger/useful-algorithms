//WITH MATRIX
#include <stdio.h>

#define MAXC 5

int main () {

    char cities[5][51] = {
        "mpolis",
        "xpolis",
        "saoz",
        "ylandia",
        "novaw",
    };

    int mtrx[MAXC][MAXC];

    for (int i = 0; i < MAXC; i++) {
        for (int j = 0; j < MAXC; j++) {
            mtrx[i][j] = 0;
        }
    }

    int roads, a, b, id;
    scanf("%d", &roads);

    for (int i = 0; i < roads; i++) {
        scanf(" %d %d", &a, &b);
        mtrx[a][b] = 1;
        mtrx[b][a] = 1;
    }

    printf("Search: ");
    scanf("%d", &id);
    for (int i = 0; i < MAXC; i++) {
        if (mtrx[id][i]) {
            printf("%s\n", cities[i]);
        }
    }

    /* SHOW EVERYTHING
    for (int i = 0; i < MAXC; i++) {
        for (int j = 0; j < MAXC; j++) {
            printf("%d ", mtrx[i][j]);
        }

        printf("\n");
    }
    */


    return 0;
}
