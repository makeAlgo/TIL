#include <string>
#include <stack>

using namespace std;

int solution(string s){
    stack<int> prevNum;    
    if(s.size() & 1) return 0; 
    
    for(int i = 0; i < s.size(); i++){
        if(prevNum.empty()){
            prevNum.push(s[i]);
            continue;
        }
        if(prevNum.top() != s[i]) prevNum.push(s[i]);
        else prevNum.pop();
    }

    return prevNum.empty() ? 1 : 0;
}