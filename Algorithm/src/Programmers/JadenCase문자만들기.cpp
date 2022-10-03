#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    for(int i = 0, len = s.size(); i < len; i++){
        if(s[i] != ' '){
            if(s[i-1] == ' ' || i == 0)
                answer += toupper(s[i]);
            else
                answer += tolower(s[i]);
        }
        else
            answer += s[i];
    }
    return answer;
}