/*
괄호가 빠져 있는 식이 있다.
적절히 괄호를 사용해 식이 최소가 되도록 만들어라.
*/
#include <stdio.h>
#include <string.h>
int main(void){


    char form[51] = {0,};
    int flag = 0, tmp = 0, sum = 0;

    scanf("%s", form);

    for(int i = 0, n = strlen(form); i < n+1; i++){
        // - 부호 나온 후의 + 들은 모두 -로 convert
        // - 부호 나오면 flag = 1;
        if(form[i] == '+' || form[i] == '-' || i == n){
            if(flag == 0){
                sum += tmp;
                tmp = 0;
            }
            else{
                sum -= tmp;
                tmp = 0;
            }
            if(form[i] == '-'){
                flag = 1;
            }
            printf("sum : %i\n", sum);
        }
        else{
            tmp = tmp*10 + ((int)form[i] - 48);
            printf("%i : %i\n", i, tmp);
        }
    }
    
    printf("output : %i", sum);

    return 0;
}