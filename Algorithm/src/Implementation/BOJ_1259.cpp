#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    while(1){
        string num, reverseNum;
        cin >> reverseNum;
        num = reverseNum;
        if(num == "0") break;

        reverse(reverseNum.begin(),reverseNum.end());

        if(num == reverseNum) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}