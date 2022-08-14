/*
1. 도시의 개수
2. 도시간 간격
3. 각 도시별 기름 가격
>> 최소 기름값 구하기
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n = 0;
    printf("도시 개수를 입력하세요 :");
    scanf("%i", &n);

    int *dist = malloc((n) * sizeof(int));
    int price = 0, min = 0;
    long long sum = 0;

    for(int i = 0; i < n-1; i++){
        printf("%i번 거리 : ", i);
        scanf("%i", dist+i);
    }
    for(int i = 0; i < n; i++){
        printf("%i번 도시 기름 가격 : ", i);
        scanf("%i", &price);

        if(i == 0 || min > price){
            min = price;
        }
        if(i == n - 1){
            dist[i] = 0;
        }
        sum += (long long)min * dist[i];
        printf("sum = %i + %i * %i\n", sum, min, dist[i]);
    }


    printf("sum : %lld", sum);


    free(dist);

    return 0;
}