#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int arr[21];
int N, S;
int cnt;
vector<pair<int,bool>> v;

int compare(pair<int,bool> p1, pair<int,bool> p2){
    return p1.first < p2.first;
}

void func(int req, int k, int num){ //req : 선택할 개수, k : 현재까지 선택한 개수, sum : 현재까지 수들의 합
    if(k == req){ // 선택할 개수만큼 선택했다면
        int sum = 0;
        for(int i = 0; i < k; i++)
            sum += arr[i];

        if(sum == S) cnt++; //합들이 S와 같아면 cnt 증가
        return;
    }

    for(int i = num; i < N; i++){
        if(!v[i].second){
            v[i].second = true;
            arr[k] = v[i].first;
            func(req,k+1,i+1);
            v[i].second = false;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // 수열 => backtracking

    cin >> N >> S;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        v.push_back(make_pair(tmp,false));
    }
    
    sort(v.begin(),v.end(),compare);
    
    for(int i = 1; i <= N; i++)
        func(i,0,0);

    cout << cnt;    
    return 0;
}