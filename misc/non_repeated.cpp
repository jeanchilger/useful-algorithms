#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

    int arr[10];
    int num = 0;
    vector<int> unrep;

    //set the data in array
    cout << "Items\n";
    int vecIndex = -1;
    for (int i = 0; i < 10; i++) {

        cin >> arr[i];
        // cout << "0\n";
        if (find(unrep.begin(), unrep.end(), arr[i]) == unrep.end()) {
            // cout << "1\n";
            unrep.push_back(arr[i]);
            vecIndex++;
            // cout << "2\n";


        } else {
            // cout << "3\n";

            unrep.erase(unrep.begin()+vecIndex);
            vecIndex--;
            // cout << "4\n";

        }
    }

    for (unsigned i = 0; i < unrep.size(); i++) {
        cout << unrep.at(i) << endl;
    }

    return 0;
}
