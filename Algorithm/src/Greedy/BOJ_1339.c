#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

    int N = 0;
    scanf("%i", &N);

    char arr[10][9];
    int alphaScore[26] = {0, };

    for(int i = 0; i < N; i++){
        scanf("%s", arr[i]);
        int len = strlen(arr[i]);
        int pow = 1;
        for(int j = len-1; j >= 0; j--){
            alphaScore[arr[i][j]-65] += pow;
            pow *= 10;
        }
    }

    int alphaNum[26] = {0, };
    int num = 9, sum = 0;
    for(int i = 0; i < 10; i++){
        int index = 0, cnt = 0;
        for(int j = 0,max = 0; j < 26; j++){
            if(alphaScore[j] != 0) cnt++;
            if(max <= alphaScore[j]){
                max = alphaScore[j];
                index = j;
            }
        }
        if(cnt == 0) break;
        alphaNum[index] = num;
        sum += alphaNum[index]*alphaScore[index];
        num--;
        alphaScore[index] = 0;
    }

    printf("%i ", sum);

    
    return 0;
}