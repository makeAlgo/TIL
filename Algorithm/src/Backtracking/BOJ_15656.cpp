#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
bool visited[10001];
vector<int> v;

void func(int k){ // 현재까지 k개 선택
    if(k == M){ // M개 선택했다면
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        arr[k] = v[i];
        func(k+1);
    }
}

int main(void){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    func(0);
    return 0;
}