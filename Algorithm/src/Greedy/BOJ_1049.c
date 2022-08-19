#include <stdio.h>

int main(void){

    int N = 0, M = 0;
    scanf("%i %i", &N, &M);

    int six = 1000, one = 1000;
    for(int i = 0,tmpS,tmpO; i < M; i++){
        scanf("%i %i", &tmpS, &tmpO);
        if(six > tmpS)
            six = tmpS;
        if(one > tmpO)
            one = tmpO;
    }

    if(N <= 6){
        if(six <= one*N)
            printf("%i\n", six);
        else
            printf("%i\n", one*N);
        return 0;
    }
    else{
        int min = 1000000;
        for(int i = 0,tmp; ; i++){
            tmp = six*i + one*(N - 6*i > 0 ? N - 6*i : 0);
            if(min > tmp)
                min = tmp;
            if(6*i >= N)
                break;
        }
        
        printf("%i\n", min);
    }

    return 0;
}
