/*
회의시간은 겹칠 수 없다. 최대한 많이 회의 할 수 있는 횟수는 ?
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    // int n = 0;
    // scanf("%i", &n);

    // int *timeTable = malloc((2 * n) * sizeof(int));
    // for(int i = 0; i < n; i++){
    //     scanf("%i %i",&timeTable[2*i], &timeTable[2*i+1]);
    // }

    int n = 11;
    int timeTable[22] = {1,4,3,5,0,6,5,7,3,8,5,9,6,10,8,11,8,12,2,13,12,14};

    //회의시간은 겹칠 수 없다.
    for(int i = 0; i < 22; i += 2){
        //0 2 4 6 8 10 12 14 16 18 20
        // for(int j = 0; )
        // if(timeTable[i+1] > timeTable[i*j+2]){

        // }
    }
    //최대한 많은 회의를 해야한다.


    free(timeTable);
    return 0;
}