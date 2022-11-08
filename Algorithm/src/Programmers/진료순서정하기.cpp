#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const int &a, const int &b){
    if(a > b) return true;
    else return false;
}

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> tmp = emergency;
    
    sort(tmp.begin(),tmp.end(), compare);
    
    int idx;
    for(int i = 0; i < emergency.size(); i++){
        idx = find(tmp.begin(), tmp.end(), emergency[i]) - tmp.begin() + 1;
        answer.push_back(idx);   
    }
    
    return answer;
}