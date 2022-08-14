/*
N이 주어진다.
A에 있는 N개의 수가 순서대로 주어지고, B에 있는 수가 순서대로 주어진다.
N은 50보다 작거나 같은 자연수이고, A와 B의 각 원소는 100보다 작거나 같은 음이 아닌 정수이다.

S의 최솟값을 출력하라.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n = 0, s = 0, max = 0, index = 0, sum = 0;
    scanf("%i", &n);
    
    int* arrA = malloc(n * sizeof(int));
    int* arrB = malloc(n * sizeof(int));
    int* flag = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%i", &arrA[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%i", &arrB[i]);
        flag[i] = 0;
    }

    //B에서 가장 큰 수 <---> A 에서 가장 작은 수
    //큰거 작은거 끼리 묶으면 된다

    //A 오름차순 정렬
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(arrA[j] < arrA[j-1]){
                int tmp = arrA[j];
                arrA[j] = arrA[j-1];
                arrA[j-1] = tmp;
            }
        }
    }

    //B 최대값 찾은 후 정렬된 A 값과 곱셈. 한번 찾아진 최대값은 flag[]로 인해 다시 나오지 않음.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(flag[j] == 0){
                if(max < arrB[j]){
                    max = arrB[j];
                    index = j;
                }
            }
        }
        flag[index] = 1;
        sum += arrA[i] * max;
        max = 0;
    }

    printf("%i", sum);
    
    free(arrA);
    free(arrB);
    free(flag);

    return 0;
}