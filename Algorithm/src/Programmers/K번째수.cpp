#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands){
    vector<int> answer;
    
    for(int t = 0; t < commands.size(); t++){
        int i = commands[t][0];
        int j = commands[t][1];
        int k = commands[t][2];
        
        vector<int> tmp;
        for(int q = i-1; q < j; q++)
            tmp.push_back(array[q]);
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp[k-1]);
    }
    return answer;
}