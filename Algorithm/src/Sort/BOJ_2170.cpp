#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2);

int main(void){
    int N;
    cin >> N;
    vector<pair<int,int>> lines;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        lines.push_back(make_pair(x,y));
    }
    
    //선이 끝나는 y로 오름차순 정렬
    sort(lines.begin(),lines.end(),compare);

    //현재 x가 이전 y보다 작거나 같으면 총 길이에 (현재 y - 이전 y) 만큼 더하기
    int total_length = lines[0].second - lines[0].first;
    int maxx = lines[0].second;
    for(int i = 1; i < N; i++){

        // cout << lines[i].first <<' '<<lines[i].second;

        if(lines[i].first <= maxx){
            if(lines[i].second > maxx){
                total_length += lines[i].second - maxx;
                maxx = lines[i].second;
            }
        }
        else{//lines[i].first > lines[i-1].second
            //사이에 있지않으면 -> 선이 끊어진 것 => 현재 (y-x) 길이를 총 길이에 더하기
            total_length += lines[i].second - lines[i].first;
            maxx = lines[i].second;
        }

        // cout << " | " << total_length;
        // cout << '\n';
    }
    cout << total_length << endl;
    return 0;
}

bool compare(pair<int,int> p1, pair<int,int> p2){
    if(p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}