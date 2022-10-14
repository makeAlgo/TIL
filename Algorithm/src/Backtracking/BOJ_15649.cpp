#include <iostream>

using namespace std;

int N, M; //1부터 N까지 자연수 중에서 중복없이 길이가 M인 수열
int arr[10];
bool visited[10];

void func(int k){ // 현재 k개까지 수를 선택
    //Base Condition
    if(k == M){ // m개를 모두 선택했다면
        for(int i = 0; i < M; i++){
            cout << arr[i] << ' ';    //graph를 출력
        }
        cout << '\n';
        return;
    }
    //else
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            arr[k] = i;
            func(k+1);
            visited[i] = false;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    func(0);
    return 0;
}