/*
1. N개의 로프는 각각 버틸 수 있는 중량이 다르다.
2. 각각의 로프에는 모두 고르게 w/n 만큼의 중량이 걸린다.
>> 주어진 로프들로 들어올릴 수 있는 물체의 최대 중량을 구하라.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n = 0, max = 0;
    scanf("%i", &n);

    int *ropes = malloc(n * sizeof(int));
    int *cal = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%i", &ropes[i]);
    }

    //내림차순 정렬 
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(ropes[j] > ropes[j-1]){
                int tmp = ropes[j];
                ropes[j] = ropes[j-1];
                ropes[j-1] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cal[i] = ropes[i] * (i+1);
        if(max < cal[i]){
            max = cal[i];
        }
    }
    
    printf("%i", max);
    free(ropes);
    free(cal);

    return 0;
}