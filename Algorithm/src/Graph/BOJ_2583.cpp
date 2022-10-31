#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
bool graph[105][105];
bool isused[105][105];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int area;
vector<int> cnt;

void bfs(int x, int y){
    int num = 0;
    area++;
    isused[x][y] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        num++;
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(0 > next_x || 0 > next_y || next_x >= N || next_y >= M) continue;
            if(!isused[next_x][next_y] && !graph[next_x][next_y]){
                isused[next_x][next_y] = 1;
                q.push(make_pair(next_x,next_y));
            }
        }
    } 
    cnt.push_back(num);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> K;

    for(int rect = 0; rect < K; rect++){
        int l_x, l_y, r_x, r_y;
        cin >> l_x >> l_y >> r_x >> r_y;
        for(int i = l_x; i < r_x; i++)
            for(int j = l_y; j < r_y; j++)
                graph[i][j] = 1;
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(!isused[i][j] && !graph[i][j]) bfs(i,j);

    sort(cnt.begin(),cnt.end());

    cout << area << '\n'; 
    for(int i = 0; i < cnt.size(); i++)
        cout << cnt[i] << ' ';
    return 0;
}