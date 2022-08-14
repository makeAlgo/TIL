/*
1차 서류심사 순위, 2차 면접시험 순위
둘 모두 다른 지원자에 비해 떨어지면 탈락
하나라도 높다면 OK
*/

#include <stdio.h>
#include <stdlib.h>

// 구조체로 1차순위 2차순위 묶기
typedef struct _person{
    int first;
    int second;
}person;

int compare(const void *a, const void *b);

int main(void){

    int testCase = 0;
    scanf("%i", &testCase);

    for(int i = 0; i < testCase; i++){ //테스트케이스
        int min = 0, cnt = 0;

        int number = 0;
        // 사람 수 입력
        scanf("%i", &number);

        person *arr = malloc(number * sizeof(person));
        // 순위 입력
        for(int j = 0; j < number; j++){
            scanf("%i %i", &arr[j].first, &arr[j].second);
        }
        //1차 시험 기준 내림차순
        //2차 시험은 1차시험 정렬에 따라 함께 정렬

        qsort((person *)arr,number,sizeof(person),compare);


        for(int q = 0; q < number; q++){
            if(q == 0){
                min = arr[q].second;
                cnt++;
            }
            if(arr[q].second < min){
                min = arr[q].second;
                cnt++;
            }
        }

        printf("%i\n", cnt);
        free(arr);
    }

    return 0;
}

int compare(const void *a, const void *b){
    int num1 = ((person *)a)->first;
    int num2 = ((person *)b)->first;

    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;

    return 0;
}
