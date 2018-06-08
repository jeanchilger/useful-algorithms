#include <iostream>

using namespace std;

int partition(int arr[], int first, int last) {
    int pivot = first;
    int low = first + 1;
    int high = last;
    int temp;

    while (low <= high) {
        if (arr[low] <= arr[pivot]) {
            low++;
        } else {
            if (arr[high] >= arr[pivot]) {
                high--;
            } else {
                temp = arr[low];
                arr[low] = arr[high];
                arr[high] = temp;
            }
        }
    }

    temp = arr[pivot];
    arr[pivot] = arr[high];
    arr[high] = temp;

    return high;

}

void quicksort(int arr[], int first, int last) {
    /*
    sorts an array in increasing order
    */
    if (first < last) {
        int p = partition(arr, first, last);

        quicksort(arr, first, p - 1);
        quicksort(arr, p + 1, last);
    }
}


int main() {

    int vec[9] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    quicksort(vec, 0, 8);

    for (int i = 0; i < 9; i++) {
        cout << vec[i] << endl;
    }

    return 0;
}
