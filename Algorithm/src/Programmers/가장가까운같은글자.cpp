#include <string>
#include <vector>

using namespace std;

int alpha[26];

void alphaInit(){
    for(int i = 0; i < 26; i++)
        alpha[i] = -1;
}

vector<int> solution(string s) {   
    vector<int> answer;
    alphaInit();
    for(int i = 0; i < s.size(); i++){
        if(alpha[s[i]-'a'] == -1) answer.push_back(-1);
        else answer.push_back(i-alpha[s[i]-'a']);
        alpha[s[i]-'a'] = i;
    }

    return answer;
}