#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
vector<pair<int,bool>> v;

int compare(pair<int,bool> p1, pair<int,bool> p2){
    return p1.first < p2.first;
}

void func(int k){ // 현재까지 k개 선택
    if(k == M){ // k개 선택했다면
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int prev_num = -1;
    for(int i = 0; i < N; i++){
        if(!v[i].second && prev_num != v[i].first){
            v[i].second = true;
            arr[k] = v[i].first;
            prev_num = v[i].first;
            func(k+1);
            v[i].second = false;
        }
    }
}

int main(void){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        v.push_back(make_pair(tmp,false));
    }
    
    sort(v.begin(),v.end(),compare);
    func(0);
    return 0;
}
