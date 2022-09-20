#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> gems;
    for(int i = 0; i < N; i++){
        int weight, price;
        cin >> weight >> price;
        gems.push_back(make_pair(weight,price));
    }
    sort(gems.begin(),gems.end(),compare);

    vector<int> bags; 
    for(int i = 0; i < K; i++){
        int capacity;
        cin >> capacity;
        bags.push_back(capacity);
    }
    sort(bags.begin(),bags.end(),less<>());

    priority_queue<int,vector<int>,less<int>> pq;
    long long sum = 0;
    int idx = 0;
    for(int i = 0; i < K; i++){
        while(idx < N && bags[i] >= gems[idx].first){
            pq.push(gems[idx++].second);
        }
        if(!pq.empty()){
            sum += pq.top(); pq.pop();
        }
    }

    cout << sum << endl;

    return 0;
}

bool compare(pair<int,int> p1, pair<int,int> p2){
    if(p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}