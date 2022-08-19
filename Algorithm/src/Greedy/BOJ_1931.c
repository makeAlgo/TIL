#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

typedef struct _meeting{
    int start, end;
}meeting;

int main(void){
    
    int N = 0;
    scanf("%i", &N);
    
    meeting *arr = malloc(N * sizeof(meeting));

    for(int i = 0; i < N; i++)
        scanf("%i %i", &arr[i].start, &arr[i].end);

    qsort(arr, N, sizeof(meeting), compare);

    for(int i = 1; i < N; i++){
        if(arr[i-1].end == arr[i].end){
            if(arr[i-1].start > arr[i].start){
                int tmp = arr[i].start;
                arr[i].start = arr[i-1].start;
                arr[i-1].start = tmp;
            }
        }
    }        

    int cnt = 0;

    for(int i = 0, tmp = 0; i < N; i++){
        if(arr[i].start >= tmp){
            cnt++;
            tmp = arr[i].end;
        }
    }
    printf("%i", cnt);

    free(arr);
    return 0;
}


int compare(const void *a, const void *b){

    int num1 = ((meeting *)a)->end;
    int num2 = ((meeting *)b)->end;

    if(num1 < num2)
        return -1;
    if(num1 > num2)
        return 1;

    return 0;
}