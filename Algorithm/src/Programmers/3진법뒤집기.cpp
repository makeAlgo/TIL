#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    string S = "";
    
    while(n != 0){
        S += to_string(n%3);
        n /= 3;  
    }

    for(int i = S.size()-1, x = 1; i >= 0; i--){
        answer += x*(S[i] - '0');
        x *= 3;
    }
    
    return answer;
}