#include <iostream>

using namespace std;

typedef long int li;

li lis(li arr[], li n) {
    /*
     * Returns the Longest Increasing Subsequence for a given
     * sequence of numbers.
     * */

    li t[n];
    for (li i = 0; i < n; i++) {
        t[i] = 1; 
    }

    for (li i = 1; i < n; i++) {
        for (li j = 0; j < i; j++) {

        }
    }
}

int main() {

    li n;
    cin >> n;

    li arr[n];
    for (li i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << lis(arr) << endl;

    return 0;
}
