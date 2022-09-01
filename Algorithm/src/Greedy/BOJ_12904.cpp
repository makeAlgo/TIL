#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    string S, T;
    cin >> S >> T;

    while(1){
        int idx = T.size();

        if(T.size() == S.size()){
            if(T == S)
                cout << '1' << endl;
            else
                cout << '0' << endl;
            break;
        }

        char tmp = T[idx-1];
        T.pop_back();
        if(tmp == 'B'){
            reverse(T.begin(),T.end());
        }   
    }

    return 0;
}