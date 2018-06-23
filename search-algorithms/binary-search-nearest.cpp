#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int arr[], double val, int start, int end, int mid) {
    /*
    return the index of the closest value that matches with a given value
    this behavior is similar to the binary insertion
    */
    if (start == end + 1) {
        if (val - arr[end] < arr[start] - val) {
            return end;
        }
        return start;

    }

    if (val == arr[mid]) {
        return mid;

    } else if (val < arr[mid]) {
        return binarySearch(arr, val, start, mid-1, (mid-1 + start) / 2);

    } else {
        return binarySearch(arr, val, mid+1, end, (end + mid+1) / 2);
    }
}

// testing the algorithm
int main() {

    cout << "Number of elements >> elements\n";
    // vector<int> vec;
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        // cin >> elem;
        // vec.push_back(elem);
    }

    double val;

    cout << "Values to find\n";
    while (1) {
        cin >> val;
        if (val < arr[0]) {
            cout << 0 << endl;
            break;
        } else if (val > arr[size-1]) {
            cout << size-1 << endl;
            break;
        }
        cout << binarySearch(arr, val, 0, size-1, size/2) << endl << endl;
    }

    return 0;
}
