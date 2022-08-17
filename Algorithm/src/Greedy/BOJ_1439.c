#include <stdio.h>
#include <string.h>

int main(void){

    char arr[1000000];
    scanf("%s", arr);

    int cnt = 0, n = 0;
    n = strlen(arr);
    for(int i = 0; i < n-1; i++){
        if(arr[i] != arr[i+1]){
            cnt++;
        }
    }
    if(cnt%2 == 0){
        cnt /= 2;
    }
    else{
        cnt = cnt/2 + 1;
    }
    printf("%i", cnt);

    return 0;
}