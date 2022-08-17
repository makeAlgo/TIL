#include <stdio.h>

int main(void){

    int money = 0, tmp = 0, cnt = 0;
    int type[2] = {5, 2};
    scanf("%i", &money);

    //1 3 원 빼고 모두 거슬러 줄 수 있다.

    if(money == 1 || money == 3){
        printf("-1");
        return 0;
    }

    for(int i = 0 ; i < 2 ; i++){
        tmp = money / type[i];

        if(((money - tmp * type[i]) % 2) != 0){
            tmp--;
        }

        money -= tmp * type[i];
        cnt += tmp;
    }
    printf("%i", cnt);
    return 0;
}