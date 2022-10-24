#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int &a, const int &b){
    if(a < b) return true; //true면 현상태 유지
    return false; //false 면 교환
}

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(),d.end(),compare);
    for(int i = 0; i < d.size(); i++){
        budget -= d[i];
        if(budget < 0) break;
        answer++;
    }
    return answer;
}