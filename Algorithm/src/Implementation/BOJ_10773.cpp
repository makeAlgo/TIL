#include <iostream>
#include <stack>

using namespace std;

int K;
stack<int> st;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;

    cin >> K;

    while(K--){
        int num;
        cin >> num;

        if(num != 0) st.push(num);
        else if(!st.empty() && num == 0) st.pop();
    }

    while(!st.empty()){
        sum += st.top();
        st.pop();
    }

    cout << sum;
    return 0;
}