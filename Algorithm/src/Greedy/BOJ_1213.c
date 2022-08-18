#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void palin(int *a);
void drome(int *a);
int checkOdd(int *a);

int main(void){

    char name[51];
    scanf("%s", name);

    int len = strlen(name);
    int index[26] = {0, };

    for(int i = 0; i < len; i++){
        index[name[i]-65]++;
    }

    int oddIndex = checkOdd(index);
    
    if(len%2 == 0){
        palin(index);
        drome(index);
    }
    else{
        palin(index);
        printf("%c",oddIndex+65);
        index[oddIndex]--;
        drome(index);
    }

    return 0;
}



void palin(int *a){
    for(int j = 0; j < 26; j++){
        if(a[j] != 0){
            int k = 0;
            while(k != a[j]/2){
                printf("%c", j+65);
                k++;
            }
            a[j] -= k;
        }
    }
}
void drome(int *a){
    for(int j = 25; j >= 0; j--){
        if(a[j] != 0){
            int k = 0;
            while(k != a[j]){
                printf("%c", j+65);
                k++; 
            }
            a[j] -= k;
        }
    }
}

int checkOdd(int *a){
    int cnt = 0, index = 0;
    for(int i = 0; i < 26; i++){
        if(a[i]%2 == 1){
            index = i;
            cnt++;
            if(cnt > 1){
                printf("I'm Sorry Hansoo\n");
                exit(0);
            }
        }
    }
    return  index;
    
}

