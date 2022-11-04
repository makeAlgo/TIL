#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int r, c;

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int bdx[4] = {0,1,0,-1};
int bdy[4] = {1,0,-1,0};

bool visited[105][105];

int bfs(int x, int y, const vector<vector<int>> &graph){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    int cnt = 0;
    
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        cnt++;
        
        for(int i = 0; i < 4; i++){
            int nx = curx + bdx[i];
            int ny = cury + bdy[i];
            
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(!visited[nx][ny] && !graph[nx][ny]){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
            }
        }
    }
    return cnt;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    r = board.size();
    c = board[0].size();
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] == 2) continue;
            else if(board[i][j] == 1){
                for(int k = 0; k < 8; k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
                    if(board[ni][nj] == 1) continue;
                    board[ni][nj] = 2;
                }
            }
        }
    }
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(!visited[i][j] && !board[i][j]) answer += bfs(i,j,board);

    return answer;
}