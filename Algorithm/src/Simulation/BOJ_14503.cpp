#include <iostream>

using namespace std;

int N, M; //세로 N, 가로 M
int r, c, d; // x좌표 r, y좌표 c, 현재 바라보는 방향 d
// d | 0 : 북, 1 : 동, 2 : 남, 3 : 서 
int graph[50][50];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt;

void func(int x, int y){
    while(1){
        if(graph[x][y] == 0){
            graph[x][y] = 2; // 2 : 청소한 칸
            cnt++;
        }

        int cantMove = 0;
        for(int i = 0; i < 4; i++){
            if(d == 0) d = 3; // 북->서->남->동->북
            else d--;
            int next_x = x + dx[d];
            int next_y = y + dy[d];
            if(graph[next_x][next_y] == 0){
                x = next_x;
                y = next_y;
                break; 
            }
            cantMove++;
        }

        if(cantMove == 4){
            int backDir;
            if (d == 0) backDir = 2;
            else if(d == 1) backDir = 3;
            else if(d == 2) backDir = 0;
            else if(d == 3) backDir = 1;

            if(graph[x+dx[backDir]][y+dy[backDir]] == 1){
                cout << cnt;
                exit(0);
            }
            else{
                x = x + dx[backDir];
                y = y + dy[backDir];
            }
        }
    }           
}

int main(void){
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> graph[i][j]; // 0 : 빈칸, 1 : 벽
    func(r,c);
    return 0;
}