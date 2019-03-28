/*
 * Simple representation of a segment tree.
 * */

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

#define INF 99999

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

void print(int n) {
    /*
     * Prints the hole tree.
     * BFS-like print.
     * */

    for (int i = 0; i < n; i++) {
        cout << "[ "
             << get<0>(st[i+1])
             << ","
             << get<1>(st[i+1])
             << "," 
             << get<2>(st[i+1])
             << " ]" 
             << endl;
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

    int x = min(get<0>(st[2 * i]), get<0>(st[(2 * i) + 1]));
    iii n (x, b, e);
    st[i] = n;
}

int query(int b, int e, int id = 1) {
    /*
     * Searches for the minimun value in the given range [b, e].
     * */

    int i = get<1>(st[id]);
    int j = get<2>(st[id]);

    if (b == i and j == e) return get<0>(st[id]);
    
    printf("i=%d j=%d id=%d\n", i, j, id);

    if (i <= b and j >= e) {
        return min(query(b, e, 2 * id), query(b, e, 2 * id + 1)); 
    
    } else if (i <= b) {
        return query(b, e, 2 * id);
    
    } else if (j >= e) {
        return query(b, e, 2 * id +1);
    }

    
    return 0;
}

int main(){
    int n, e, b;

    cin >> n;
    cin >> b >> e;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    iii f (9, 0, 0);
    st.assign(2*n, f);
    
    fill(1, n, 1, arr);
    print(2*n - 1);
    cout << "query(" << b <<" , "<< e <<  ") = " << query(b, e) << endl;

    return 0;
}
