#include<stdio.h>
#define n 100
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
        int index=partition(arr,low,high);
        quick_sort(arr,low,index-1);
        quick_sort(arr,index+1,high);
    }
}


void main(){
    int a[n];
    int i=0;
    for(i=0;i<=100;i++){
        a[i]=i;
    }
    quick_sort(a,0, n-1);
     for(i=0;i<=100;i++){
        printf("%d",a[i]);
        
    }
}