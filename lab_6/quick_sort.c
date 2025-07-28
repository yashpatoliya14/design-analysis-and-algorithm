#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

int readFromFile(const char *filename, int arr[], int n)
{
    FILE *ptr = fopen(filename, "r");
    if (!ptr)
    {
        printf("File not found.\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(ptr, "%d", &arr[i]);
    }

    fclose(ptr);
    return 1;
}

int partition(int arr[], int low, int high)
{
    int p = arr[low];
    int k = low;
    int j = high + 1;
    k++;
    while (k < high && arr[k] <= p)
    {
        k++;
    }
    j--;
    while (j > low && arr[j] > p)
    {
        j--;
    }

    while (k < j)
    {

        int temp = arr[k];
        arr[k] = arr[j];
        arr[j] = temp;

        k++;
        while (k < high && arr[k] <= p)
        {
            k++;
        }
        j--;
        while (low < j && arr[j] > p)
        {
            j--;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quick_sort(int arr[], int low, int high)
{   
    
    if (low < high)
    {
        int index = partition(arr, low, high);
        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}

void main() {
    int arr[N];
    clock_t start, end;
    double timeTaken;

    if (readFromFile("./array_10000.txt", arr, N)) {
        start = clock();

        quick_sort(arr,0, N-1);

        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        printf("Time taken by selection Sort: %f ms\n", timeTaken);
    }
}
