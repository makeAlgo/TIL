#include <stdio.h>
int ab(int a, int b);

int main(void){

    int n = 0;
    scanf("%i", &n);

    int level[100];

    for(int i = n-1; i >= 0; i--){
        scanf("%i", &level[i]);
    }

    int tmp = 0, cnt = 0;

    for(int i = 1; i < n; i++){
        if(level[i-1] <= level[i]){
            tmp = ab(level[i-1],level[i]) + 1;
            level[i] -= tmp;
            cnt += tmp;
        }
    }
    printf("%i\n", cnt);

    return 0;
}

int ab(int a, int b){
    if(a-b > 0){
        return a-b;
    }
    else if(a-b < 0 ){
        return -(a-b);
    }
    else{
        return 0;
    }
}