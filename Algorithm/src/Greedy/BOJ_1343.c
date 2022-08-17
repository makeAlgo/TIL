#include <stdio.h>
#include <string.h>

int main(void){

    int n = 0, cnt = 0;
    char input[50];

    scanf("%s", input);

    n = strlen(input);

    for(int i = 0; i < n; i++){
        if(input[i] == 'X'){
            cnt ++;
        }
        else if(input[i] == '.'){
            if(cnt % 2 != 0){
                printf("-1");
                return 0;
            }
            cnt = 0;
        }
        if(cnt == 4){
            for(int j = 0; j < 4; j++){
                input [i-j] = 'A';
            }
            cnt = 0;
        }
        if(cnt == 2){
            for(int j = 0; j < 2; j++){
                input [i-j] = 'B';
            }
        }
        if(i == n-1){
            if(cnt % 2 == 1){
                printf("-1");
                return 0;
            }
        }
        
    }

    printf("%s", input);
    return 0;
}