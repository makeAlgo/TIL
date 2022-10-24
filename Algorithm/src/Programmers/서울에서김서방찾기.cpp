#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 에 있다";
    
    for(int i = 0, len = seoul.size(); i < len; i++){
        if(seoul[i] == "Kim"){
            answer = answer.insert(answer.find(' ')+1, to_string(i));
            break;
        }
    }
    
    return answer;
}