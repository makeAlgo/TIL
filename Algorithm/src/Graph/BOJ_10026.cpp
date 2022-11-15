#include <iostream>
#include <queue>

using namespace std;

char graph[110][110];
bool isused[110][110];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int N;
int area, weaknessArea;

void isusedInit(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            isused[i][j] = false;
}

int bfs(int x, int y, bool flag){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    isused[x][y] = true;
    if(flag == true && graph[x][y] == 'R') graph[x][y] = 'G';
    
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(flag == true && graph[nx][ny] == 'R') graph[nx][ny] = 'G';

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(!isused[nx][ny] && graph[nx][ny] == graph[curx][cury]){
                q.push(make_pair(nx,ny));
                isused[nx][ny] = true;
            }
        }
    }
    return 1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> graph[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!isused[i][j]) area += bfs(i,j,false);

    isusedInit();

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!isused[i][j]) weaknessArea += bfs(i,j,true);
            
    cout << area << ' ' << weaknessArea;
    return 0;
}