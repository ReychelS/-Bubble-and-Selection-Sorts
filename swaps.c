#include <stdio.h>

void swap(int* a, int* b, int* count) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*count)++;
}

//bubble sort 
void bubbleSort(int arr[], int n, int swapCount[], int* totalSwaps) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1], totalSwaps);
                swapCount[arr[j+1]]++;
                swapCount[arr[j]]++;
            }
        }
    }
}

//selection sort 

void selectionSort(int arr[], int n, int swapCount[], int* totalSwaps) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i], totalSwaps);
            swapCount[arr[i]]++;
            swapCount[arr[min_idx]]++;
        }
    }
}

//print swaps
void printSwaps(int arr[], int n, int swapCount[], int totalSwaps) {
    for(int i = 0; i < n; i++) {
        printf("%d: %d times\n", arr[i], swapCount[arr[i]]);
    }
    printf("Total Number of swaps: %d\n\n", totalSwaps);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1)/sizeof(array1[0]);
    int n2 = sizeof(array2)/sizeof(array2[0]);
    int swapCount1[100] = {0}, swapCount2[100] = {0};
    int totalSwaps1 = 0, totalSwaps2 = 0;

    // Bubble Sort on array1
    printf("Bubble Sort on array1:\n");
    bubbleSort(array1, n1, swapCount1, &totalSwaps1);
    printSwaps(array1, n1, swapCount1, totalSwaps1);

    // Resetting swap counts for the next sort
    for(int i = 0; i < 100; i++) swapCount1[i] = 0;
    totalSwaps1 = 0;

    // Selection Sort on array2
    printf("Selection Sort on array2:\n");
    selectionSort(array2, n2, swapCount2, &totalSwaps2);
    printSwaps(array2, n2, swapCount2, totalSwaps2);

    return 0;
}
