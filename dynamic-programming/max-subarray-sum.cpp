#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> cache;
vector<int> array;
int n;

int solve (int i) {
    /*
    Returns the biggest sum for a contiguous subarray of an array with n size.
    */
    if (i >= n) return 0;
    if (cache[i] != -1) return cache[i];

    int a = array[i];
    int b = array[i] + solve(i+1);

    return cache[i] = max(a, b);
}

int main () {

    int l;
    cout << "Array size: ";
    cin >> n;

    cout << "Insert " << n << " elements:\n";

    cache.assign(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> l;
        array.push_back(l);
    }


    int r = -999;
    for (int i = 0; i < n; i++) {
        r = max(r, solve(i));
    }

    // int r = solve(0);
    for (int i = 0; i < n; i++) {
        cout << cache[i] << "\n";
    }

    cout << r << "\n";

    return 0;
}
