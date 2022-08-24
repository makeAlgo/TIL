#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int main(void){
    int N;
    cin >> N;
    vector<pair<int,int>> time(N);
    for(int i = 0; i < N; i++){
        cin >> time[i].first >> time[i].second;
    }

    sort(time.begin(), time.end());
    pq.push(time[0].second);
    
    for(int i = 1; i < N; i++){
        
        if(time[i].first >= pq.top()){
            pq.pop();
            pq.push(time[i].second);
        }
        else
            pq.push(time[i].second);
    }

    cout << pq.size() << endl;
    return 0;
}