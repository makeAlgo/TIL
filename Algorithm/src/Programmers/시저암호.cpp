#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            if(s[i]+n > 'Z') answer += s[i]-'Z'+'A'-1+n;
            else answer += s[i] + n;
        }
        else if('a' <= s[i] && s[i] <= 'z'){
            if(s[i]+n > 'z') answer += s[i]-'z'+'a'-1+n;
            else answer += s[i] + n;
        }
        else answer += ' ';
    }
    return answer;
}