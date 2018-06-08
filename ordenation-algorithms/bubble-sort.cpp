#include <iostream>

using namespace std;

int * bubbleSort(int arr[], int size) {
    /*
    sorts the array in decreasing order;
    */
    int temp;

    for(int i = 0; i < size; i++) {

        for(int j = 0; j < size; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr;
}

int main() {

    int vec[5] = {4, 2, 5, 1, 3};
    int* arr = bubbleSort(vec, 5);

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
