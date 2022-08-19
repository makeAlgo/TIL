#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int compare2(const void *a, const void *b);

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
    qsort(arr, N, sizeof(meeting),compare2);       

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
int compare2(const void *a, const void *b){

    meeting num1 = *(meeting *)a;
    meeting num2 = *(meeting *)b;

    if(num1.end == num2.end && num1.start < num2.start)
        return -1;
    if(num1.end == num2.end && num1.start > num2.start)
        return 1;

    return 0;
}