#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> vec, float val, int start, int end, int mid) {
    /*
    return the index of the closest value that matches with a given value
    */
    if (start == end + 1) {
        return start;
    }

    if (val == vec.at(mid)) {
        return mid;
    } else if (val < vec.at(mid)) {
        return binarySearch(vec, val, start, mid-1, (mid-1 + start) / 2);
    } else {
        return binarySearch(vec, val, mid+1, end, (end + mid+1) / 2);
    }
}

int main() {

    cout << "Number of elements >> elements\n";
    vector<int> vec;
    int vSize, elem;
    cin >> vSize;
    for (int i = 0; i < vSize; i++) {
        cin >> elem;
        vec.push_back(elem);
    }

    float val;

    cout << "Values to find\n";
    while (1) {
        cin >> val;
        if (val < vec.at(0)) {
            cout << 0 << endl;
            break;
        } else if (val > vec.at(vec.size()-1)) {
            cout << vec.size()-1 << endl;
            break;
        }
        cout << binarySearch(vec, val, 0, vec.size()-1, vec.size()/2) << endl << endl;
    }

    return 0;
}
