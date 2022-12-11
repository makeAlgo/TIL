#include <iostream>
#include <queue>

using namespace std;

string S;
int r,c;
char graph[55][55];
int dist[55][55];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void distInit(){
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            dist[i][j] = -1;
}

int bfs(int x, int y){
    queue<pair<int,int>> q;
    dist[x][y] = 0;
    q.push(make_pair(x,y));
    int maxx = 0;

    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        maxx = max(maxx, dist[cur_x][cur_y]);

        for(int i = 0; i < 4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(dist[nx][ny] == -1 && graph[nx][ny] == 'L'){
                q.push(make_pair(nx,ny));
                dist[nx][ny] = dist[cur_x][cur_y] + 1;
            }
        }
    }
    return maxx;
}

int main(void){
    int answer = 0;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> S;
        for(int j = 0; j < c; j++)
            graph[i][j] = S[j];
    }

    distInit();

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            if(graph[i][j] == 'L' && dist[i][j] == -1){
                answer = max(answer,bfs(i,j));
                distInit();
            }
        }

    cout << answer;
    return 0;
}