#include <iostream>
#include <queue>
#include <utility>

#define MAX_SIZE 50

using namespace std;

int w, h;
int graph[MAX_SIZE][MAX_SIZE];
int visited_bfs[MAX_SIZE][MAX_SIZE];

//현재 좌표와 인접한 좌표 방향; 숫자키패드(6,9,8,7,4,1,2,3) 순서
int x_dir[8] = {1,1,0,-1,-1,-1,0,1};
int y_dir[8] = {0,-1,-1,-1,0,1,1,1};

void bfs(int start_y, int start_x){
    //시작 좌표를 방문했다고 표시
    visited_bfs[start_y][start_x] = 1;
    //시작 좌표와 인접한 좌표를 탐색하기 위해 queue에 push
    queue<pair<int,int>> q;
    q.push(make_pair(start_y,start_x));

    while(!q.empty()){
        //탐색할 좌표 설정
        int y = q.front().first;
        int x = q.front().second;
        //다음 탐색에서 제외하기위해 제거
        q.pop();

        //탐색할 좌표와 인접한 8개의 좌표
        for(int i = 0; i < 8; i++){
            int adj_y = y + y_dir[i];
            int adj_x = x + x_dir[i];

            //인접한 좌표에 대해 3가지 조건 비교
            //1. 방문했던 좌표인가? -> no
            //2. 현재좌표와 연결된 좌표인가? -> yes
            //3. graph안에 존재하는 좌표인가? -> yes
            if(!visited_bfs[adj_y][adj_x] && graph[adj_y][adj_x]
            && (0 <= adj_y && adj_y < h) && (0 <= adj_x && adj_x < w)){
                //인접한 좌표를 방문했다고 표시
                visited_bfs[adj_y][adj_x] = 1;
                //인접한 좌표에 인접한 좌표를 bfs하기 위해 queue에 push
                q.push(make_pair(adj_y,adj_x));
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        //지도 입력
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> graph[i][j];
                //방문 기록 초기화 == linked edge 초기화
                //memset(visited_bfs, 0, sizeof(visited_bfs));
                visited_bfs[i][j] = 0;
            }
        }
        
        int land_cnt = 0;
        //모든 좌표에 대해 bfs
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                //방문한적이 없는 땅을 bfs
                if(graph[i][j] && !visited_bfs[i][j]){
                    bfs(i,j);
                    land_cnt++;
                }                
            }
        }
        cout << land_cnt << endl;
    }

    return 0;
}