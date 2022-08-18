#include <stdio.h>
#include <string.h>

int main(void){

    char L[11], R[11];  
    scanf("%s %s", L, R);
    int lenL = strlen(L);
    int lenR = strlen(R);

    if(lenL != lenR){
        printf("0\n");
    }
    else{
        int cnt = 0;
        for(int i = 0; i < lenL; i++){
            if(L[i] != R[i]) break;
            if(L[i] == '8' && R[i] == '8') cnt++;
        }
        printf("%i\n", cnt);
    }

    return 0;
}