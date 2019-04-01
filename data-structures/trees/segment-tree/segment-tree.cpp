/*
 * Simple representation of a segment tree.
 * The criterion of the search can be changed in the merge method.
 * The line 91 of search may require changes as well.
 * */

#include <cstdio>
#include <tuple>
#include <vector>

using namespace std;

#define INF 9999

typedef tuple<int, int, int> iii;
typedef vector <iii> viii;

viii st;
// st[i] -> (val, b, e)
// where val is the min value between the interval [b, e]

int min(int a, int b) {
    /*
     * Returns the minimun of a and b.
     * */

    return a < b ? a : b;
}

int max(int a, int b) {
    /*
     * Returns the maximun of a and b.
     * */

    return a > b ? a : b;
}

int merge(int a, int b) {
    /*
     * Combines the two given values of the tree.
     * */

    return max(a, b);
}

void print(int n) {
    /*
     * Prints the hole tree.
     * BFS-like print.
     * */

    for (int i = 0; i < n; i++) {
        printf("[%d, %d, %d]\n", get<0>(st[i+1]), get<1>(st[i+1]), get<2>(st[i+1]));
    }

    return;
}

void fill(int b, int e, int i, int arr[]) {
    /*
     * Builds the tree with the intervals and the values.
     * */

    if (b == e) {
        iii n(arr[b-1], b, e);
        st[i] = n;
        return;
    }
    
    fill(b, (b+e)/2, i*2, arr);
    fill((b+e)/2 +1, e, i*2 + 1, arr);

    int x = merge(get<0>(st[2 * i]), get<0>(st[(2 * i) + 1]));
    iii n (x, b, e);
    st[i] = n;
}

int search(int b, int e, int id = 1) {
    /*
     * Searches for the minimun value in the given range [b, e].
     * Returns the value of this element or INF if there is no such a element.
     * */

    int i = get<1>(st[id]);
    int j = get<2>(st[id]);

    if ((b == i && j == e) || (b <= i && e >= j)) {
        return get<0>(st[id]);
    }

    if (j < b || i > e) {
        return -INF;
    }

    if (i <= b || j >= e) {
        return merge(search(b, e, 2 * id), search(b, e, 2 * id + 1));  
    }
}

void update(int idx, int newVal, int arr[], int id=1) {
    /*
     * Updates the array in the given position.
     * The intervals of the tree are updated as well.
     * */

    int i = get<1>(st[id]);
    int j = get<2>(st[id]);


    if ((idx == i && idx == j)) {
        iii n(newVal, i, j);
        st[id] = n;
        arr[i-1] = newVal;
        return ;
    }
     
     
    if (j < idx || i > idx) {
        return ;      
    }
     
    if (i <= idx || j >= idx) {
        update(idx, newVal, arr, 2 * id);
        update(idx, newVal, arr, 2 * id + 1);
    }

    int v = merge(get<0>(st[2 * id]), get<0>(st[2 * id + 1]));
    iii m(v, i, j);
    st[id] = m;
}

int main(){
    int n, e, b, o;

    scanf(" %d", &n);
   
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }

    iii f (0, 0, 0);
    st.assign(2*n, f);
    
    fill(1, n, 1, arr);
    while (scanf(" %d", &o)!= EOF) {
        scanf(" %d %d", &b, &e);
        if (o == 1) {    
            int val = search(b, e);
            printf("search(%d, %d) = %d\n", b, e, val);
        } else {
            update(b, e, arr);
        }
    }

    return 0;
}
