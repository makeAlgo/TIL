#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const int &a, const int &b){
    if(a > b) return true;  //true면 유지
    return false;   //false면 교환
}

int solution(vector<int> citations) {
    int N = citations.size();
    int answer = 0;
    
    sort(citations.begin(),citations.end(),compare);
    
    if(!citations[0]) return 0;
    for(int i = 0; i < N; i++)
        if(citations[i] > i) answer++;

    return answer;
}