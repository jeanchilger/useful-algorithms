#include <stdio.h>
#include <vector>

using namespace std;

void printArray(double *arr, int size) {
    /*
     * Simple utility function to print an array
     * */

    printf("[ ");
    for (int i = 0; i < size-1; i++) {
        printf("%.2lf, ", arr[i]);
    }
    printf("%.2lf ]\n", arr[size-1]);
}

void insertionSort(vector<double> &arr, int size) {
    /*
     * Sorts the given array in increasing order.
     * Used here as an intermediary sorting algorithm.
     * */

    double key;
    int j;
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

// >>>>>>>>>>>>> Important part
void bucketSort(double *arr, int size) {
    /*
     * Sorts an array with value range within [0,1) in increasing order.
     * */

    vector<vector<double> > buckets(size);
    int v;
    for (int i = 0; i < size; i++) {
        v = arr[i] * size;
        buckets[v].push_back(arr[i]);
        insertionSort(buckets[v], buckets[v].size());
    }

    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}
// <<<<<<<<<<<<<

// tests
int main() {

    int n;
    printf("Number of elements in array: ");
    scanf(" %d", &n);

    double arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf(" %lf", &arr[i]);
    }

    /*n = 10;
    double arr[n] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};*/

    printf("Original array: \n");
    printArray(arr, n);

    bucketSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
