#include <string>
#include <vector>
#include <queue>

using namespace std;

void makeGroup(const string &s, vector<string> &v){
    queue<char> q;
    string tmp = "";
    int idx = 0;
    
    q.push(toupper(s[idx++]));
    while(!q.empty() && idx < s.size()){
        q.push(toupper(s[idx++]));
        if(q.size() == 2){
            char a = q.front(); q.pop();
            char b = q.front();
            
            if(a < 'A' || b < 'A' || 'Z' < a || 'Z' < b) continue;
            
            tmp += a; tmp += b;
            v.push_back(tmp);
            tmp = "";      
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    
    makeGroup(str1, v1);    
    makeGroup(str2, v2);
    
    int x = 0;
    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v2.size(); j++){
            if(v1[i] == v2[j]){
                x++;
                v2[j] = ' ';
                break;
            } 
        }
    }
    int y = v1.size() + v2.size() - x;
    
    if(y == 0) return 65536;
    return x*65536/y;
}