#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        string S;
        getline(cin, S);
        if(S == ".") break;

        stack<char> st;
        bool check = false;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '(' || S[i] == '[') st.push(S[i]);
            else if (S[i] == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else{
                    check = true;
                    break;
                }
            }
            else if(S[i] == ']'){
                if(!st.empty() && st.top() == '[') st.pop();
                else{
                    check = true;
                    break;
                }
            }
        }

        if(check == false && st.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}