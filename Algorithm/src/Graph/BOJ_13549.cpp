#include <iostream>
#include <queue>
using namespace std;

int dist[100005];
int dir[3] = {2,1,-1};
int N, K;

void bfs(int st, int en){
    dist[st] = 0;
    queue<int> q;
    q.push(st);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == en) break;

        for(int i = 0; i < 3; i++){
            int nx, time = 0;
            if(i == 0){
                nx = cur * dir[i];
            }
            else{
                nx = cur + dir[i];
                time = 1;
            } 

            if(nx < 0 || nx > 100000) continue;
            if(dist[nx] > dist[cur] + time){
                q.push(nx);
                dist[nx] = dist[cur] + time;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    fill(dist,dist+100005,0x7f7f7f7f);

    bfs(N, K);
    cout << dist[K];
    return 0;
}