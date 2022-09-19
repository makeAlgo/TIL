#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, maxx = 0;
    cin >> N;
    vector<pair<int,int>> homework; 
    for(int i = 0; i < N; i++){
        int requiredTime, deadline;
        cin >> requiredTime >> deadline;
        homework.push_back(make_pair(requiredTime,deadline));
    }

    sort(homework.begin(),homework.end(),compare);

    int playDay = homework[0].second;
    for(int i = 0; i < N; i++){
        if(homework[i].second < playDay)
            playDay = homework[i].second;
        playDay -= homework[i].first;
    }

    if(playDay < 0) playDay = 0;
    cout << playDay << endl;
    return 0;
}

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second > p2.second;
}