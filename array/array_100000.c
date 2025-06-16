#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100000

void best_case(){
    FILE *f = fopen("array_100000.txt","w");

    for(int i = 1 ; i <= N; i++ ){
        fprintf(f,"%d ",i);
    }
    fprintf(f,"\n");
    fclose(f);
}


void worst_case(){
    FILE *f = fopen("array_100000.txt","a");

    for(int i = N ; i > 0; i-- ){
        fprintf(f,"%d ",i);
    }
    fprintf(f,"\n");

    fclose(f);
}

void average_case(){
    int arr[N];
    for (int i = 1; i <= N; i++)
    {
        arr[i] = i + 1; 
    }
    srand(time(NULL));
    for (int i = 1; i <= N; i++)
    {
        int j = rand() % (i+1);
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
    FILE *f = fopen("array_100000.txt","a");

    for(int i = N ; i > 0; i-- ){
        fprintf(f,"%d ",arr[i]);
    }
    fprintf(f,"\n");

    fclose(f);
}

int main()
{
    best_case();
    worst_case();
    average_case();
    return 0;
}
