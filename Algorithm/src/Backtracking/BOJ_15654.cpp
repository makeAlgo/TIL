#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int arr[10];
bool visited[10001];
int N, M;

void func(int k){ // 현재까지 k개 선택
    if(k == M){ // 현재 M개 선택했다면 
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(!visited[v[i]]){
            visited[v[i]] = true;
            arr[k] = v[i];
            func(k+1);
            visited[v[i]] = false;
        }
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