#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> v;
bool visited[105][105];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N, M;

int bfs(int x, int y, char target){
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;

    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        cnt++;

        for(int i = 0; i < 4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(!visited[nx][ny] && v[nx][ny] == target){
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
            }
        }
    }
    return cnt*cnt;    
}

int main(void){
    queue<pair<int,int>> ally;
    queue<pair<int,int>> enemy;

    cin >> N >> M;
    int allyForce = 0;
    int enemyForce = 0;

    for(int i = 0; i < M; i++){
        string S = "";
        cin >> S;
        v.push_back(S);
    }

    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++){
            if(!visited[i][j] && v[i][j] == 'W') allyForce += bfs(i,j,'W');
            else if(!visited[i][j] && v[i][j] == 'B') enemyForce += bfs(i,j,'B');
        }
    
    cout << allyForce << ' ' << enemyForce;
    return 0;
}