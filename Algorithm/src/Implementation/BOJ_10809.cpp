#include <iostream>
#include <vector>

using namespace std;

int main(void){
    string S;
    cin >> S;

    vector<int> alphabet(26,-1);
    for(int i = 0; i < S.size(); i++){
        if(alphabet[S[i]-'a'] == -1)
            alphabet[S[i]-'a'] = i;
    }

    for(int i = 0; i < alphabet.size(); i++){
        cout << alphabet[i] << ' ';
    }

    return 0;
}