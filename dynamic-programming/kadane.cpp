#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> array;
int n;

int kadane () {
    /*
    kadane algorithm finds the biggest sum of a contiguous subarray within an array.
    */
    int maxSoFar = array[0]; // biggest sum of subarray;
    int maxEndHere = array[0]; // biggest sum of subarray that ends at index i;
    for (int i = 1; i < n; i++) {
        maxEndHere = max(array[i],
                         maxEndHere + array[i]);
        if (maxEndHere > maxSoFar) {
            maxSoFar = maxEndHere;
        }
    }

    return maxSoFar;
}

int main () {

    int l;
    cout << "Array size: ";
    cin >> n;

    cout << "Insert " << n << " elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> l;
        array.push_back(l);
    }



    cout << kadane() << "\n";

    return 0;
}
