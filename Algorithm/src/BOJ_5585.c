/*
지불할 가격이 입력될 때 거스름돈의 개수가 가장 적게 되도록 하라.
나에겐 1000원이 있고 화폐는 500, 100, 50, 10, 5, 1 이 있다.
*/

#include <stdio.h>

int main(void){

    int unit[6] = {500, 100, 50, 10, 5, 1};
    int counterMoney = 1000;
    int price = 0, cnt = 0, sum = 0;
    
    printf("price : ");
    scanf("%i", &price);

    int tmp = counterMoney - price;

    for(int i = 0; i < 6; i++){
        cnt = tmp / unit[i];    //거스름돈 개수 확인
        tmp -= cnt * unit[i];   //남은 거스름돈 조정
        sum += cnt;
        cnt = 0;
    }

    printf("%i",sum);

    return 0;
}
