#include <iostream>
#include <queue>

using namespace std;

int M, N;
int graph[1010][1010];
bool isused[1010][1010];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool bfs(int x, int y){
    isused[x][y] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(!isused[nx][ny] && graph[nx][ny] == 0){
                q.push(make_pair(nx,ny));
                isused[nx][ny] = true;
            }
        }
    }

    for(int i = 0; i < N; i++)
        if(isused[M-1][i]) return 1;
    return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    string S;
    for(int i = 0; i < M; i++){
        cin >> S;
        for(int j = 0; j < N; j++)
            graph[i][j] = S[j] - '0';
    }

    for(int i = 0; i < N; i++)
        if(!isused[0][i] && !graph[0][i]){
            if(bfs(0,i)){
                cout << "YES" << '\n';
                return 0;
            }
        }

    cout << "NO" << '\n';
    return 0;
}