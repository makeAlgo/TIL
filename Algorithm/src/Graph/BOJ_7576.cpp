#include <iostream>
#include <queue>
#define MAX_SIZE 1000

using namespace std;

int graph[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int N, M; // 세로 N, 가로 M
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int date;

queue<pair<int,int>> q;

void bfs(){
    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if(dist[next_x][next_y] == -1 && graph[next_x][next_y] == 0
            && (0 <= next_x && next_x < N) && (0 <= next_y && next_y < M)){
                dist[next_x][next_y] = dist[now_x][now_y] + 1;
                q.push(make_pair(next_x,next_y));
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[i][j];
            dist[i][j] = -1;
            if(graph[i][j] == 1){
                q.push(make_pair(i,j));
                dist[i][j]++;
            } 
        }
    }

    bfs();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dist[i][j] == -1 && graph[i][j] == 0){
                cout << -1;
                return 0;
            }
            date = max(dist[i][j],date);
        }
    }

    cout << date;
    return 0;
}