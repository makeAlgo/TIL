#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
bool compare(pair<int,int> a, pair<int,int> b);

int main(void){
    int N;
    cin >> N;
    
    vector<pair<int,int>> v;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),compare);

    for(int i = 0; i < N; i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
    
    return 0;
}

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}