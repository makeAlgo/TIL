#include <string>
#include <vector>

using namespace std;

int total[201];

int solution(vector<vector<int>> lines) {
    int answer = 0;
    
    for(int i = 0; i < lines.size(); i++){
        int idx = 100;
        int st = lines[i][0];
        int en = lines[i][1];
        idx += st;
        
        for(int k = st; k < en; k++)
            total[idx++]++;
    }
    
    for(int i = 0; i < 201; i++)
        if(total[i] > 1) answer++;
    
    return answer;
}