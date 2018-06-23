#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> vec, int val) {
    /*
    return the position of a value at a given orded vector
    */
    int start = 0;
    int end = vec.size() - 1;
    int mid = (end + start) / 2;

    while(true) {
        if (val == vec.at(mid)) {
            return mid;
        } else if (val < vec.at(mid)) {
            end = mid-1;
            mid = (end + start) / 2;
        } else {
            start = mid+1;
            mid = (end + start) / 2;
        }
    }
}

// testing the algorithm
int main() {

    cout << "Number of elements >> elements\n";
    vector<int> vec;
    int vSize, elem, val;
    cin >> vSize;
    for (int i = 0; i < vSize; i++) {
        cin >> elem;
        vec.push_back(elem);
    }

    cout << "Values to find\n";
    while (1) {
        cin >> val;
        cout << binarySearch(vec, val) << endl << endl;
    }

    return 0;
}
