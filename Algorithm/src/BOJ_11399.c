/*
입력 : 첫째 줄에 사람의 수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄에는 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어진다. (1 ≤ Pi ≤ 1,000)
출력 : 첫째 줄에 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int people = 0, cnt = 0, sum = 0;

    scanf("%i", &people);
    int* min = malloc(people * sizeof(int));

    for(int i = 0; i < people; i++){
        scanf("%i", &min[i]);
    }
    
    for(int j = 0; j < people; j++){
        for(int l = 1; l < people; l++){
            if(min[l] < min[l-1]){
                int tmp = min[l-1];
                min[l-1] = min[l];
                min[l] = tmp;
            }       
        }
    }

    for(int k = 0; k < people; k++){
        cnt += min[k];
        sum += cnt;
    }

    printf("%i", sum);
    free(min);

    return 0;
}