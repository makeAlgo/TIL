#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b);

int main(void){
    int N;
    cin >> N;
    vector<pair<int,int>> v(N);

    for(int i = 0; i < N; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(),v.end());

    int prev = v[0].first;
    v[0].first = 0;
    for(int i = 1; i < N; i++){
        if(v[i].first == prev){
            v[i].first = v[i-1].first;
        }
        else if(v[i].first > prev){
            prev = v[i].first;
            v[i].first = v[i-1].first + 1;
        } 
    }

    sort(v.begin(),v.end(),compare);

    for(int i = 0; i < N; i++){
        cout << v[i].first << ' ';
    }

    return 0;
}

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}