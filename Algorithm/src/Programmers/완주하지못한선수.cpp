#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string,int> m;
    
    for(auto 사람 : participant){
        if(m.find(사람) == m.end()) m.insert(make_pair(사람,1));
        else m[사람]++;
    }
    
    for(auto 사람 : completion)
        if(m.find(사람) != m.end()) m[사람]--;
    
    for(auto 사람 : participant)
        if(m[사람] > 0) return 사람;
}