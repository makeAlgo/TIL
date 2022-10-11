#include <iostream>
#include <queue>
#include <cstring>
#define MAX_SIZE 100001

using namespace std;

int graph[MAX_SIZE];
int N, K; // N 시작 위치, K 타겟 위치
queue<int> q;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    memset(graph, -1, MAX_SIZE*sizeof(int));

    q.push(N);
    graph[N] = 0;

    while(graph[K] == -1){
        int cur = q.front();
        q.pop();

        for(int nxt : {cur-1, cur+1, cur*2}){
            if(0 <= nxt && nxt < MAX_SIZE && graph[nxt] == -1){
                graph[nxt] = graph[cur]+1;
                q.push(nxt);
            }
        }
    }
    cout << graph[K];
    return 0;
}