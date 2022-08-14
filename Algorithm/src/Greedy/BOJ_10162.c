/*
A B C 버튼은 각각 300초 60초 10초가 더해지는 버튼이다.
주어진 시간을 최소버튼조작으로 맞추어라.
*/

#include <stdio.h>

int main(void){

    int button[3] = {300, 60, 10};
    int cnt[3] = {0,};
    int time = 0; 

    scanf("%i", &time);

    if(time % 10 == 0){
        for(int i = 0; i < 3; i++){
            cnt[i] = time / button[i];
            time -= cnt[i] * button[i];
            printf("%i ", *(cnt+i));
        }
    }
    else{
        printf("-1");
    }

    return 0;
}