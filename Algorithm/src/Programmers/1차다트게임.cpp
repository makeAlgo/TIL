#include <string>

using namespace std;

int scores[5]; //기회 3번
string tmp = "";

void calScores(const string &S){
    int idx = -1;
    for(int i = 0; i < S.size(); i++){
        if('0' <= S[i] && S[i] <= '9') tmp += S[i];
        else{
            if(tmp != ""){
                scores[++idx] = stoi(tmp);
                tmp = "";
            }
            if(S[i] == 'D'){//제곱
                scores[idx] *= scores[idx];
            }
            else if(S[i] == 'T'){//세제곱
                scores[idx] = scores[idx] * scores[idx] * scores[idx];
            }
            if(S[i] == '*'){
                scores[idx] *= 2;
                if(idx-1 < 0) continue;
                scores[idx-1] *= 2;
            }
            else if(S[i] == '#'){
                scores[idx] *= -1;
            }
        }
    }
}

int solution(string dartResult) {
    int answer = 0;

    calScores(dartResult);
    
    for(int i = 0; i < 3; i++)
        answer += scores[i];
    return answer;
}