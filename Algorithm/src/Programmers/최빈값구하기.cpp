#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> numOfCnt(1001);

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first > b.first) return true;
    else return false;
}

int solution(vector<int> array) {
    int answer = 0;
    
    for(int i = 0; i < array.size(); i++){
        numOfCnt[array[i]].first++;
        numOfCnt[array[i]].second = array[i];
    }
    
    sort(numOfCnt.begin(),numOfCnt.end(),cmp);
    
    if(numOfCnt[0].first == numOfCnt[1].first) answer = -1;
    else answer = numOfCnt[0].second;
    
    return answer;
}