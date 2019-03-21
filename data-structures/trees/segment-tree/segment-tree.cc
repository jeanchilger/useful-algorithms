#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector <iii> viii;

viii st;

int min(int a, int b) {
    return a < b ? a : b;
}


void bfs(int n) {
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

int query(int b, int e) {

    return 0;
}

int main(){
    int n;

    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    iii f (9, 0, 0);
    st.assign(2*n, f);
    
    fill(1, n, 1, arr);
    bfs(2*n - 1);

    return 0;
}
