#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define START_VERTEX_NUM 1

int vertex_cnt, edge_cnt;
int graph[101][101]; //2차원 그래프 각 노드연결 정보
bool visit_dfs[101]; //1차원 방문한 위치정보 저장
int cnt;

void dfs(int cur_vertex_num){
    //현재 노드를 방문했다고 표시
    visit_dfs[cur_vertex_num] = true;
    //1번부터 모든노드까지 2가지 조건 비교
    for(int i = 1; i <= vertex_cnt; i++){
        //1. i번 노드를 방문했는가?
        //2. 현재노드와 i번 노드가 연결되어 있는가?
        if(!visit_dfs[i] && graph[cur_vertex_num][i] == 1){
            cnt++;
            //i번 노드와 연결된 노드 탐색; 재귀
            dfs(i);
        }
    }
}

int main(void){
    cin >> vertex_cnt;
    cin >> edge_cnt;

    for(int i = 0; i < edge_cnt; i++){
        int source, dest;
        cin >> source >> dest;
        graph[source][dest] = 1;
        graph[dest][source] = 1;
    }

    dfs(START_VERTEX_NUM);
    cout << cnt << endl;
    return 0;
}

