#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<long,int> p1, pair<long, int> p2);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<long long> cards;
    for(int i = 0; i < N; i++){
        long long num;
        cin >> num;
        cards.push_back(num);
    }

    sort(cards.begin(),cards.end());

    vector<pair<long long, int>> numCounter;
    numCounter.push_back(make_pair(cards[0],1));
    int idx = 0;
    for(int i = 1; i < N; i++){
        if(cards[i] == cards[i-1]){
            numCounter[idx].second++;
        }
        else{        
            numCounter.push_back(make_pair(cards[i],1));
            idx++;
        }
    }
    sort(numCounter.begin(),numCounter.end(),compare);

    cout << numCounter[0].first << endl;
    return 0;
}

bool compare(pair<long,int> p1, pair<long, int> p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}