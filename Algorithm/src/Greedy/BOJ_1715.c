/*
N개의 카드묶음이 주어진다.
카드묶음의 각 카드 수가 주어진다.
카드묶음을 합치려면 비교해야 하는데 예를 들면 10과 20을 합치려면
30번의 비교가 필요하다.
최소한의 비교를 구하라.
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void){

    int n = 0, sum = 0;
    scanf("%i", &n);
    int *arr = malloc( n * sizeof(int));

    // 각 카드 수 입력
    for(int i = 0; i < n; i++){
        scanf("%i", arr+i);
    }
    
    qsort((int *)arr, n, sizeof(int),compare);

    int tmp = arr[0];
    for(int i = 1; i < n; i++){
        tmp += arr[i];
        sum += tmp;
    }

    printf("%i", sum);
    free(arr);

    return 0;
}

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 < num2)
        return -1;

    if(num1 > num2)
        return 1;

    return 0;
}