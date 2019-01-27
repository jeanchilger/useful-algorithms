#include <stdio.h>

using namespace std;

void printArray(int *arr, int size) {
    /*
     * Simple utility funciton to print an array.
     * */

    printf("[ ");
    for (int i = 0; i < size-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n", arr[size-1]);
}

// >>>>>>>>>>>>> Important part
void insertionSort(int *arr, int size) {
    /*
     * Sorts the given array in increasing order.
     * */

    int key, j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}
// <<<<<<<<<<<<<

// tests
int main() {

    int n;
    printf("Number of elemts in array: ");
    scanf(" %d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf(" %d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    insertionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
