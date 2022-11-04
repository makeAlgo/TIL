#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> v(2);
vector<pair<int,int>> 기울기;
bool isused[10];

void func(int k, int num, vector<vector<int>> &dots){
    if(k == 2){
        int 분자 = v[0].second - v[1].second;
        int 분모 = v[0].first - v[1].first;
        
        if(분모 == 0) return;
        else 기울기.push_back(make_pair(분자 / 분모,분자 % 분모));
        return;
    }
    for(int i = num; i < dots.size(); i++){
        if(!isused[i]){
            isused[i] = true;
            v[k] = make_pair(dots[i][0], dots[i][1]);
            func(k+1,i,dots);
            isused[i] = false;
        }
    }
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    func(0, 0, dots);
    
    for(int i = 0; i < 기울기.size(); i++)
        for(int j = i+1; j < 기울기.size(); j++)
            if(기울기[i] == 기울기[j]) return 1;
    return 0;
}