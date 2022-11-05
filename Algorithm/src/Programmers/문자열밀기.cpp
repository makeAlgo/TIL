#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    int N = A.size();
    deque<char> dq;
    string S = "";
    
    for(int i = 0; i < N; i++){
        dq.push_back(A[i]);
        S += dq[i];
    }
    
    while(N--){
        if(S == B) return answer; 
        dq.push_front(dq.back());
        dq.pop_back();
        answer++;
        S = "";
        for(int i = 0; i < dq.size(); i++)
            S += dq[i];
    }
    
    return -1;
}