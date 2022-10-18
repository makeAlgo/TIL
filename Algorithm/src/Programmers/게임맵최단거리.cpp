#include <vector>
#include <queue>
using namespace std;

int N, M;
int dist[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(const vector<vector<int>> &maps){
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0]++;
    
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(0 > next_x || next_x >= N || 0 > next_y || next_y >= M) continue;
            if(maps[next_x][next_y] && dist[next_x][next_y] == 0){
                q.push(make_pair(next_x,next_y));
                dist[next_x][next_y] = dist[cur_x][cur_y] + 1;
            }
        }
    }
}

int solution(vector<vector<int> > maps){
    N = maps.size();
    M = maps[0].size();
    
    bfs(maps);

    return dist[N-1][M-1] == 0 ? -1 : dist[N-1][M-1];
}