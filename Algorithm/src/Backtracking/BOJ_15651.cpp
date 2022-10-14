#include <iostream>

using namespace std;

int N, M;
int arr[10];

void func(int k){ // 현재 k개 선택
    if(k == M){ // M개 선택했다면
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        arr[k]= i;
        func(k+1);
    }
}

int main(void){
    cin >> N >> M;
    func(0);

    return 0;
}