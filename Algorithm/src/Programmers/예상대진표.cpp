#include <iostream>
#include <queue>

using namespace std;
queue<pair<int,char>> q;

void pushQ(pair<int,char> tmp1, pair<int,char> tmp2){
    if(tmp1.second > tmp2.second){
            if(tmp1.first%2 == 1)
                tmp1.first = tmp1.first/2 + 1;
            else
                tmp1.first /= 2;
            q.push(tmp1);
        }
        else{
            if(tmp2.first%2 == 1)
                tmp2.first = tmp2.first/2 + 1;
            else
                tmp2.first /= 2;
            q.push(tmp2);
        }
}

int solution(int n, int a, int b) {
    int answer = 1, idx = 0;
    
    for(int i = 1; i <= n; i++){
        if(i == a)
            q.push(make_pair(i,'a'));
        else if(i == b)
            q.push(make_pair(i,'b'));
        else
            q.push(make_pair(i,' '));
    }
    
    while(!q.empty()){       
        auto tmp1 = q.front(); q.pop();
        auto tmp2 = q.front(); q.pop(); 
        
        if(tmp1.second != ' ' && tmp2.second != ' ') break;
        
        pushQ(tmp1, tmp2);
        
        idx += 2;
        if(idx == n){
            idx = 0;
            answer++;
            n/=2;
        }
    }
    
    return answer;
}