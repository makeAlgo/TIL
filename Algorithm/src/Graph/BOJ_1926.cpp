#include <iostream>
#include <queue>
#define MAX_SIZE 500
using namespace std;

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int n, m; //세로크기 n, 가로크기 m
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(int x, int y){ // x 열, y 행
    int width = 0;
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        width++;

        for(int i = 0; i < 4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(!visited[next_x][next_y] && graph[next_x][next_y]
            && (0 <= next_x && next_x < n) && (0 <= next_y && next_y < m)){
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x,next_y));
            }
        }
    }
    return width;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int paintCnt = 0, maxWidth = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> graph[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && graph[i][j]){
                maxWidth = max(bfs(i,j),maxWidth);
                paintCnt++;
            }
        }
    }

    cout << paintCnt << '\n' << maxWidth;
    return 0;
}