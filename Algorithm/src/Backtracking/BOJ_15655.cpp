#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
bool visited[10001];
vector<int> v;

void func(int num, int k){ // 현재까지 k개 선택
    if(k == M){ // M개 선택했다면
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num; i < N; i++){
        if(!visited[v[i]]){
            visited[v[i]] = true;
            arr[k] = v[i];
            func(i+1, k+1);
            visited[v[i]] = false;
        }
    }
}

int main(void){
    //수열 구하기 => Back Tracking
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    func(0,0);
    return 0;
}