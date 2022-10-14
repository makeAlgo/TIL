#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool visited[10];

void func(int num, int k){ //현재 k개 선택
    if(k == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = num; i <= N; i++){
        if(!visited[i]){
            arr[k] = i;
            visited[i] = true;
            func(i+1, k+1);
            visited[i] = false;
        }
    }
}

int main(void){
    cin >> N >> M;
    func(1,0);

    return 0;
}