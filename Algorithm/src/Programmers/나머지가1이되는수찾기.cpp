#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    for(answer; ; answer++){
        if(n % answer == 1)
            break;
    }
    
    return answer;
}