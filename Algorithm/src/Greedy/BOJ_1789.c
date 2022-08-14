/*
서로 다른 N 개의 자연수의 합이 S이다.
자연수 N의 최댓값은 얼마인가.
>> 주어진 S를 더해서 만드는데 필요한 자연수의 개수의 최대값은?
*/

#include <stdio.h>

int main(void){

    //sum에 i 더함
    //S와 sum의 차이 확인 >> tmp
    //tmp = 10 , i = 20 
    //tmp가 i보다 작으면 종료

    long long num = 0, tmp = 0;
    int cnt = 0;

    scanf("%lld", &num);

    do{
        cnt++;  //1부터 시작
        tmp = num - cnt;
        num -= cnt;
    }while(tmp > cnt);
    printf("%i",cnt);

    return 0;
}