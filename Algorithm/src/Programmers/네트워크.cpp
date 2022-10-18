#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){ 
            visited[i] = 1;
            queue<int> q;
            q.push(i);
            
            while(!q.empty()){
                int next_i = q.front();
                q.pop();
                for(int j = 0; j < n; j++){
                    if(!visited[j] && computers[next_i][j]){
                        q.push(j);
                        visited[next_i] = 1;
                    }
                }
            }
            answer++;
        }
    }
    return answer;
}