#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int n = 0, price = 0, cnt = 0, sum = 0;
    scanf("%i %i", &n, &price);

    int* types = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
       scanf("%i", types+i);
    }
    
    int j = n-1;
    do{
        if(types[j] <= price){
            cnt = price / types[j];
            sum += cnt;
            price -= cnt * types[j];
        }
        j--;
    }while(price != 0);

    printf("%i",sum);

    free(types);
    return 0;
}