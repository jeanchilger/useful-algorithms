#include <iostream>
#include <stdio.h>

using namespace std;

void printArray(int arr[], int size) {
    /*
     * Simple utility function to print beutifully an array.
     * */

    printf("[ ");
    for (int i=1; i < size; i++) {
        printf("%d, ", arr[i-1]);
    }

    printf("%d ]\n", arr[size-1]);

}

// >>>>>>> Important part

void merge(int * arr, int low, int mid, int high) {
    /*
     * Utility function to merge two subarrays.
     * */

    int li = low;
    int ri = mid+1;
    int i = 0;
    int temp[high-low+1];
    int l = low;

    while (li <= mid || ri <= high) {
       
        if (li > mid && ri <= high) {
           temp[i] = arr[ri];
            ri++;

        } else if (ri > high && li <= mid) {
            temp[i] = arr[li];
            li++;

        } else if (li <= mid && ri <= high) {

            if (arr[li] < arr[ri]) {
                temp[i] = arr[li];
                li++;

            } else {
                temp[i] = arr[ri];
                ri++;
            }
        }

        i++;
    }

    for (int i = 0; i < high-low+1; i++) {
        arr[l] = temp[i];
        l++;
    }
}

void mergesort(int * arr, int low, int high) {
    /*
     * Sorts an array with indexes from low to high in increasing order.
     * */

    if (low >= high) return;
    
    int mid = (high - low) / 2 + low;


    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);

    merge(arr, low, mid, high);

}

// <<<<<<<

int main() {

    int n;
    
    printf("Number of elments in array: ");
    scanf(" %d", &n);

    int arr[n];
    for (int i=0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf(" %d", &arr[i]);
    }

    //int arr[4] = {4, 3, 1, 2};
    //int arr[8] = {7, 5, 6, 4, 2, 3, 1, 8};

    printf("Original array: \n");
    printArray(arr, n);

    mergesort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
