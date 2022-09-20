#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,char> p1, pair<int,char> p2);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word;
    cin >> word;

    vector<pair<int,char>> alphabet(26);
    for(int i = 0; i < word.size(); i++){
        int idx = toupper(word[i]) - 65;
        alphabet[idx].first++;
        alphabet[idx].second = toupper(word[i]);
    }

    sort(alphabet.begin(),alphabet.end(),compare);
    
    if(alphabet[0].first == alphabet[1].first)
        cout << '\?' << endl;
    else
        cout << alphabet[0].second << endl;
    
    return 0;
}

bool compare(pair<int,char> p1, pair<int,char> p2){
    return p1.first > p2.first;
}