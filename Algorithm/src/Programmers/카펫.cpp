#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int cal;
    
    for(int i = 1; i <= yellow; i++){
        for(int j = 1; j <= yellow; j++){
            cal = 2*i + 2*j + 4; //(i+2)*(j+2) - i*j
            if(cal == brown && i*j == yellow){
                answer.push_back(max(j+2,i+2));
                answer.push_back(min(j+2,i+2));
                return answer;
            }
            else if(cal > brown) break;
        }
    }
}