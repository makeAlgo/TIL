#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int graph[105][105];
bool isused[105][105];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N, M;
int time, remainedCheeses;

void bfs(){
    isused[0][0] = true;
    queue<pair<int,int>> q;
    queue<pair<int,int>> border;
    q.push(make_pair(0,0));

    while(!q.empty()){
        remainedCheeses = q.size();
        while(!q.empty()){
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            for(int i = 0; i < 4 ; i++){
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];

                if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
                if(!isused[next_x][next_y]){
                    if(graph[next_x][next_y] == 0)
                        q.push(make_pair(next_x,next_y));
                    if(graph[next_x][next_y] == 1)
                        border.push(make_pair(next_x,next_y));

                    isused[next_x][next_y] = true;
                }
            }
        }
        while(!border.empty()){
            q.push(border.front());
            border.pop();
        }
        time++;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> graph[i][j];
        }
    }

    bfs();
    cout << time-1 << '\n' << remainedCheeses;
    return 0;
}