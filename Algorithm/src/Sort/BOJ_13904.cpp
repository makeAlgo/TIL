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
        int d, w;
        cin >> d >> w;
        homework.push_back(make_pair(d,w));
        maxx = max(maxx,d);
    }

    sort(homework.begin(),homework.end(),compare);

    int result = 0;
    vector<int> schedule(maxx+1);
    for(int i = 0; i < N; i++){
        for(int j = homework[i].first; j > 0; j--){
            if(!schedule[j]){
                schedule[j] = 1;
                result += homework[i].second;
                break;
            }
        }
    }

    cout << result << endl;
    
    return 0;
}

bool compare(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second; 
}