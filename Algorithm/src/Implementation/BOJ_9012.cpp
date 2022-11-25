#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        string S;
        stack<char> st;
        bool check = true;
        cin >> S;
        
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '(') st.push(S[i]);
            else if(S[i] == ')'){
                if(!st.empty()) st.pop();
                else{
                    check = false;
                    break;
                }
            } 
        }
        
        if(check && st.empty()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}