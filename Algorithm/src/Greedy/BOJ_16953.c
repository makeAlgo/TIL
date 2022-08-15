/*
A를 B로 바꾸려고함
가능한 연산은 2가지
1. 2를 곱한다.
2. 1을 수의 가장 오른쪽에 추가한다.
*/

#include <stdio.h>

int main(void){

    int a = 0 , b = 0, cnt = 0;
    scanf("%i %i", &a, &b);

    while(1){
        // 1이면 1 떼기 1이 아닌 홀수라면 바로 -1 출력
        // 짝수라면 나누기 2
        // 반복 , 1 떼거나 2로 나눌때마다 카운트 1씩 증가
        // b가 a가 되면 알고리즘 종료
        // b가 a가 안되고 0이 되면 -1을 출력하면서 종료

        if(b == a){
            cnt++;
            printf("cnt = %i", cnt);
            break;
        }
        if(b < a){
            printf("-1");
            break;
        }
        if(b%2 != 0){ // b가 홀수라면
            if(b%10 == 1){ // b끝자리가 1이라면
                cnt++;
                b = (b - 1) / 10;
                printf("%i\n", b);
            }
            else{
                printf("-1");
                break;
            }
        }
        else{   //짝수라면
            cnt++;
            b = b / 2;
            printf("%i\n", b);
        }
    }

    return 0;
}