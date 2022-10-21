#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int graph[105][105];
bool visited[105][105];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(int x, int y, int limit){
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
            if(graph[next_x][next_y] > limit && !visited[next_x][next_y]){
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x,next_y));
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int maxx = 0;
    int waterHeight = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            int tmp;
            cin >> tmp;
            graph[i][j] = tmp;
            waterHeight = max(tmp,waterHeight);
        }
            
    while(waterHeight--){
        int tmp = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && graph[i][j] > waterHeight){
                    bfs(i,j,waterHeight);
                    tmp++;
                }
            }
        memset(visited,false,sizeof(visited));
        maxx = max(tmp,maxx);
    }

    cout << maxx;
    return 0;
}