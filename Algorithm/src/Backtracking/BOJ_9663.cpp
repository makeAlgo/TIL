#include <iostream>

using namespace std;

int N;
bool isused1[15]; //열     y
bool isused2[29]; //대각선 x+y
bool isused3[29]; //대각선 x-y+n-1
int caseCnt;

void func(int cur){ //현재 Queen의 개수
    //Base Condition
    if(cur == N){   //Queen의 개수가 N개라면 cnt 증가
        caseCnt++;
        return;
    }
    //else
    for(int i = 0; i < N; i++){
        if(isused1[i] || isused2[cur+i] || isused3[cur-i+N-1]) continue;
        isused1[i] = true;
        isused2[cur+i] = true;
        isused3[cur-i+N-1] = true;
        func(cur+1);
        isused1[i] = false;
        isused2[cur+i] = false;
        isused3[cur-i+N-1] = false;
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    func(0);
    cout << caseCnt;

    return 0;
}