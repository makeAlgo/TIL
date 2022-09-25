#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

#define MAX_SIZE 50

using namespace std;

int M, N, K; //배추밭 가로, 세로, 배추개수
int graph[MAX_SIZE][MAX_SIZE];
int vistied_bfs[MAX_SIZE][MAX_SIZE];

//인접 배추 좌표탐색을 위한 설정
int x_dir[4] = {1,0,-1,0};
int y_dir[4] = {0,1,0,-1};

void bfs(int start_x, int start_y){
    vistied_bfs[start_x][start_y] = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(start_x,start_y));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int adj_x = x + x_dir[i];
            int adj_y = y + y_dir[i];

            if(!vistied_bfs[adj_x][adj_y] && graph[adj_x][adj_y]
            && (0 <= adj_x && adj_x < N) && (0 <= adj_y && adj_y < M)){
                q.push(make_pair(adj_x,adj_y));
                vistied_bfs[adj_x][adj_y] = 1;
            }
        }
    }    
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        //각 테이스트케이스를 위해 초기화
        memset(graph, 0, sizeof(graph));
        memset(vistied_bfs, 0, sizeof(vistied_bfs));

        cin >> M >> N >> K;
        for(int i = 0; i < K; i++){
            int X, Y;
            cin >> X >> Y;
            graph[Y][X] = 1;
        }

        int bugs_cnt = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!vistied_bfs[i][j] && graph[i][j]){
                    bfs(i,j);
                    bugs_cnt++;
                }
            }
        }

        cout << bugs_cnt << endl;
    }

    return 0;
}