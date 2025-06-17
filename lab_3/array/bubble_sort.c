#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000

int readFromFile(const char *f ,int arr[] ,int n){
    FILE *ptr = fopen(f,"r");
    if(!ptr){
        printf("File not found");
        return 0 ;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(ptr,"%d",&arr[i]);
    }
    fclose(ptr);
    return 1;
}

void bubbleSort(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[j]>arr[i]){
                int temp = arr[i];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        
    }
    
}

void main(){
    int arr[N];
    clock_t start , end;
    double time;

    if(readFromFile("array_1000.txt",arr,N)){
        start = clock();
        bubbleSort(arr,N);
        end = clock();
        time = ((double)(end-start))/ CLOCKS_PER_SEC * 1000;
        printf("%f ms",time);
    }
}