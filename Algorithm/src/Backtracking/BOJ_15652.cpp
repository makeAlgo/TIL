#include <iostream>
using namespace std;

int N, M;
int arr[10];

void func(int num, int k){ //현재 k개 선택
    if(k == M){ //M개 선택했을 때
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = num; i <= N; i++){
        arr[k] = i;
        func(i,k+1);
    }
}

int main(void){
    cin >> N >> M;
    func(1,0);

    return 0;
}