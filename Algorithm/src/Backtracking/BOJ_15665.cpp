#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
vector<int> v;

void func(int k){ // 현재까지 k개 선택
    if(k == M){ // k개 선택했다면 
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int prev_num = -1;
    for(int i = 0; i < N; i++){
        if(prev_num != v[i]){
            prev_num = v[i];
            arr[k] = v[i];
            func(k+1);
        }
    }
}

int main(void){
    //수열 => back tracking
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