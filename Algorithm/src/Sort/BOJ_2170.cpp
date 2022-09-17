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

    int N;
    cin >> N;
    vector<pair<int,int>> lines;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        lines.push_back(make_pair(x,y));
    }
    
    sort(lines.begin(),lines.end(),compare);

    int total_length = lines[0].second - lines[0].first;
    int maxx = lines[0].second;
    for(int i = 1; i < N; i++){
        if(lines[i].first <= maxx){
            if(lines[i].second > maxx){
                total_length += lines[i].second - maxx;
                maxx = lines[i].second;
            }
        }
        else{//lines[i].first > lines[i-1].second
            total_length += lines[i].second - lines[i].first;
            maxx = lines[i].second;
        }
    }
    cout << total_length << endl;
    return 0;
}

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}