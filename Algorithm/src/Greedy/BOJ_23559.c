#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void){

    int N = 0, X = 0;
    scanf("%i %i", &N, &X);
    
    int A = 0, B = 0, sum = 0;
    int arr[100000] = {0,};

    for(int i = 0; i < N; i++){
        scanf("%i %i", &A, &B);

        if(A > B) arr[i] = A-B; 

        sum += B;
        X -= 1000;
    }

    qsort(arr,N,sizeof(int),compare);
    for(int i = 0; i < N; i++){
        if(X >= 4000){
            sum += arr[i];
            X -= 4000;
        }
    }
    printf("%i", sum);

    return 0;
}

int compare(const void *a, const void *b){
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 < num2)
        return 1;
    if(num1 > num2)
        return -1;
    
    return 0;
}