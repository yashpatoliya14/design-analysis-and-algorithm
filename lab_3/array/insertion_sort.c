#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

// Read array from file
int readFromFile(const char *filename, int arr[], int n) {
    FILE *ptr = fopen(filename, "r");
    if (!ptr) {
        printf("File not found.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fscanf(ptr, "%d", &arr[i]);
    }

    fclose(ptr);
    return 1;
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Main function
void main() {
    int arr[N];
    clock_t start, end;
    double timeTaken;

    if (readFromFile("array_1000.txt", arr, N)) {
        start = clock();

        insertionSort(arr, N);

        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        printf("Time taken by Insertion Sort: %.3f ms\n", timeTaken);
    }
}
