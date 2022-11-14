#include <iostream>
#include <queue>

using namespace std;

int sheeps;
int wolves;

char graph[260][260];
bool isused[260][260];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int R, C;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    isused[x][y] = true;
    int oCnt = 0, vCnt = 0;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        if(graph[curx][cury] == 'o') oCnt++;
        else if (graph[curx][cury] == 'v') vCnt++;

        for(int i = 0; i < 4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(!isused[nx][ny] && graph[nx][ny] != '#'){
                q.push(make_pair(nx,ny));
                isused[nx][ny] = true;
            }

        }
    }
    if(oCnt > vCnt) sheeps += oCnt;
    else wolves += vCnt;
}

int main(void){
    cin >> R >> C;

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> graph[i][j];

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(!isused[i][j] && graph[i][j] != '#') bfs(i,j);

    cout << sheeps << ' ' << wolves;
    return 0;
}