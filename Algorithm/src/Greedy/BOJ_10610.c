/*
N은 최대 100000개의 숫자로 구성된 수 이다.
N에 포함된 숫자를 조작해 30의 배수 중 가장 큰 수로 만들어라.
30의 배수가 되지 않는다면 -1 출력
\*/

#include <stdio.h>
#include <string.h>


int main(void){
    char num[100001] = {0,};
    scanf("%s", num);
    int n = strlen(num);
    int sum = 0, flag = 0;

    for(int i = 0; i < n; i++){
        sum += ((int) num[i] - 48);
        if(num[i] == '0'){
            flag = 1;
        }
    }

    if(sum%3 != 0){
        flag = 0;
    }

    if(flag == 1){
        //내림차순 정렬
        for(int i=0; i < n; i++){
            for(int j = 1; j < n; j++){
                if(num[j-1] < num[j]){
                    char tmp = num[j];
                    num[j] = num[j-1];
                    num[j-1] = tmp;
                }
            }
        }
        printf("%s", num);
    }
    else{
        printf("-1");
    }

    return 0;
}