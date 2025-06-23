#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

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

// selection sort
void selectionSort(int arr[], int n) {
    int min;
    for (int i = 0; i < n; i++) {
        min=i;
        for (int j = i; j < n; j++)
        {
            if(arr[min]>arr[i]){
                min=i;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// Main function
void main() {
    int arr[N];
    clock_t start, end;
    double timeTaken;

    if (readFromFile("./array_10000.txt", arr, N)) {
        start = clock();

        selectionSort(arr, N);

        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        printf("Time taken by selection Sort: %f ms\n", timeTaken);
    }
}
