#include <iostream>

using namespace std;

int count = 0;
int remaining;
int res = 0;

void walkThrough (int arr[], int step, int size) {

    int index = step - 1;
    while (remaining > 1) {

        if (arr[index % size] >= 0) {

            if ((count % 3 != 0) || (count == 0)) {
                arr[index % size] = -1;
                remaining--;

            } else {
                res = index % size;
            }

        }

        index += step;
        count++;
    }

}

int main () {

    int arr[8] = {1,2,3,4,5};
    remaining = 5;

    walkThrough(arr, 2, 5);
    cout << arr[res] << " has survived!\n";

    return 0;
}
