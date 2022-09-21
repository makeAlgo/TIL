#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define MAX 101
#define X_ORIGIN 0
#define Y_ORIGIN 0

int graph[MAX][MAX];
int visited_bfs[MAX][MAX];
int dist[MAX][MAX];

int x_dir[4] = {0, 0, -1, 1};   //x좌표 상하좌우
int y_dir[4] = {1, -1, 0, 0};   //y좌표 상하좌우

int N, M;

void bfs(int start_x, int start_y){
    //시작좌표를 방문했다고 표시
    visited_bfs[start_x][start_y] = 1;
    queue<pair<int,int>> q;
    //시작좌표의 x,y좌표를 queue에 push
    q.push(make_pair(start_x,start_y));
    dist[start_x][start_y]++;

    while(!q.empty()){
        //queue의 가장 앞 좌표를 탐색
        int x = q.front().first;
        int y = q.front().second;
        //가장 앞 좌표을 pop해 다음 탐색에서 제외
        q.pop();
        //탐색하는 좌표와 인접한 좌표 확인
        for(int i = 0; i < 4; i++){
            //현재 좌표와 상하좌우로 인접한 좌표
            int adj_x = x + x_dir[i];
            int adj_y = y + y_dir[i];
            
            //현재좌표에 상하좌우로 인접한 좌표를 3가지 조건으로 비교
            //1. 인접한 좌표가 그래프안에 존재하는가? -> yes
            //2. 인접한 좌표를 방문했는가? -> no
            //3. 인접한 좌표로 이동(가능 == 1)할 수 있는가? -> yes
            if(!visited_bfs[adj_x][adj_y] && graph[adj_x][adj_y] == 1
            && (0 <= adj_x && adj_x < N) && (0 <= adj_y && adj_y < M)){
                //인접한 좌표를 방문했다고 표시
                visited_bfs[adj_x][adj_y] = 1;
                //인접한 좌표에 인접한 좌표를 탐색하기 위해 queue에 push
                q.push(make_pair(adj_x,adj_y));
                //dist 그래프에 원점부터 좌표까지의 거리를 저장
                dist[adj_x][adj_y] = dist[x][y] + 1;
            }
        }
    }
}

int main(void){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string row;
        cin >> row;

        for(int j = 0; j < M; j++){
            graph[i][j] = row[j] - '0';
        }
    }

    bfs(X_ORIGIN, Y_ORIGIN);

    cout << dist[N-1][M-1] << endl;
    return 0;
}