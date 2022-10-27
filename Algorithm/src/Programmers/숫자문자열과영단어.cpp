#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string answer= "";
    string tmp = "";
    
    for(int i = 0; i < s.size(); i++){
        if('0'<= s[i] && s[i] <= '9') answer += s[i];
        else{
            tmp += s[i];
        
            if(tmp == "zero"){
                answer += '0';
                tmp = "";
            }
            else if(tmp == "one"){
                answer += '1';
                tmp = "";
            }                
            else if(tmp == "two"){
                answer += '2';
                tmp = "";
            }            
            else if(tmp == "three"){
                answer += '3';
                tmp = "";
            }
            else if(tmp == "four"){
                answer += '4';
                tmp = "";
            }
            else if(tmp == "five"){
                answer += '5';
                tmp = "";
            }
            else if(tmp == "six"){
                answer += '6';
                tmp = "";
            }
            else if(tmp == "seven"){
                answer += '7';
                tmp = "";
            }
            else if(tmp == "eight"){
                answer += '8';
                tmp = "";
            }
            else if(tmp == "nine"){
                answer += '9';
                tmp = "";
            }
        }
    }
    return stoi(answer);
}