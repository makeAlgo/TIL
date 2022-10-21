#include <iostream>
#include <queue>

using namespace std;

int n, m;
int p1, p2;
int x, y;
bool graph[105][105];
int dist[105];

void bfs(){
    queue<int> q;
    q.push(p1);

    while(!q.empty()){
        int cur_vertex = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(dist[i] == 0 && graph[cur_vertex][i]){
                dist[i] = dist[cur_vertex] + 1;
                q.push(i);
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;           //사람 수
    cin >> p1 >> p2;    //관계 확인 할 사람 번호
    cin >> m;           //부모자식 관계 수

    for(int i = 0; i < m; i++){
        cin >> x >> y;  //x가 부모 y가 자식
        graph[x][y] = true;
        graph[y][x] = true;
    }

    bfs();

    if(dist[p2] == 0)
        dist[p2] = -1;

    cout << dist[p2];
    return 0;
}