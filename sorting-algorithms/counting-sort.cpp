#include <stdio.h>

using namespace std;

void printArray(int * arr, int size) {
    /*
     * Simple utility function to print beutifully an array.
     * */

    printf("[ ");
    for (int i = 0; i < size-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d ]\n", arr[size-1]);
}

// >>>>>>>>>>>>> Important part

void countingSort(int *arr, int *res, int size) {
    /*
     * Sorts an array of size n in increasing order.
     * */

    int big = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > big) big = arr[i];
    }

    int count[big+1] = {0};
    for (int i = 0; i < size; i++) {
        count[arr[i]] += 1;
    }

    for (int i = 1; i <= big; i++) {
        count[i] += count[i-1];
    }

    for (int i = size-1; i >= 0; i--) {
        res[count[arr[i]] - 1] = arr[i];
        count[arr[i]] -= 1;
    }

}

// <<<<<<<<<<<<<

int main() {

    int n;
    printf("Number of elements in array: ");
    scanf(" %d", &n);

    int arr[n];
    int res[n]; // result
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf(" %d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    countingSort(arr, res, n);
    printf("Sorted arary: \n");
    printArray(res, n);


    

    return 0;
}
