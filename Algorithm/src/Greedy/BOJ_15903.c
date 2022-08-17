#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main(void){

    int n = 0, m = 0;
    long long arr[1001];
    long long sum = 0;
    scanf("%i %i", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
        if(m == 0){
            sum += arr[i];
            if(i == n - 1){
                printf("%lld\n", sum);
                return 0;
            }
        }
    }

    for(int i = 0; i < m; i++){
        qsort(arr,n,sizeof(long long),compare);
        arr[0] = arr[0] + arr[1];
        arr[1] = arr[0];
    }

    for(int i = 0; i < n; i ++){
        sum += arr[i];
    }

    printf("%lld\n", sum);
        
    return 0;
}


int compare(const void *a, const void *b){
    long long num1 = *(long long *)a;
    long long num2 = *(long long *)b;

    if(num1 < num2){
        return -1;
    }
    if(num1 > num2){
        return 1;
    }
    return 0;
}