#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[1001][1001];
bool visit_bfs[1001];

int vertex_cnt, edge_cnt;

void bfs(int start_vertex_num){
    //시작 노드를 방문했다고 표시
    visit_bfs[start_vertex_num] = true;
    queue<int> q;
    //queue에 시작위치 push
    q.push(start_vertex_num);
    //queue가 빌 때 까지 동작
    while(!q.empty()){
        //queue의 가장 앞 노드를 탐색
        int cur_vertex_num = q.front();
        //pop해서 이후의 탐색에서 제외
        q.pop();

        //1번부터 모든 노드까지 2가지 조건 비교
        for(int i = 1; i <= vertex_cnt; i++){
            //1. i번 노드를 방문했는가? -> no
            //2. 현재 노드와 i번 노드가 연결되어 있는가? -> yes
            if(!visit_bfs[i] && graph[cur_vertex_num][i] == 1){
                //조건을 만족하면 i번 노드를 방문했다고 표시
                visit_bfs[i] = true;
                //i번 노드와 연결되어 있는 노드를 탐색하기 위해 queue에 push
                q.push(i);
            }
        }
    }

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> vertex_cnt >> edge_cnt;
    
    int source, dest;
    for(int i = 0; i < edge_cnt; i++){
        cin >> source >> dest;
        graph[source][dest] = 1;
        graph[dest][source] = 1;
    }

    int cnt = 0;
    for(int i = 1; i <= vertex_cnt; i++){
        if(!visit_bfs[i]){
            bfs(i);
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}