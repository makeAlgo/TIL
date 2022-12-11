#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<string> st;

string solution(vector<int> food) {
    string answer = "";
    
    for(int i = 1; i < food.size(); i++){
        int n = food[i] / 2;
        string S;
        for(int j = 0; j < n; j++)
            S += i + '0';
        answer += S;     
        st.push(S);
    }
    
    answer += '0';
    
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }
    
    return answer;
}