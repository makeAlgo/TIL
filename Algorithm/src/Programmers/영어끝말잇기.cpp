#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> records;
    int round = 1, personNum;
    
    records.insert(words[0]);
    
    for(int i = 1, len = words.size(); i < len; i++){
        if(i%n == 0) round++;
        personNum = i%n + 1;
        
        if(records.find(words[i]) == records.end())
            records.insert(words[i]);
        else break;           
        
        if(words[i].size() == 1) break;     
        if(words[i-1].back() != words[i].front()) break;
        
        if(i == len-1){ personNum = 0; round = 0; }
    }
    
    answer.push_back(personNum);
    answer.push_back(round);

    return answer;
}