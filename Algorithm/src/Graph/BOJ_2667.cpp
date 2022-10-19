#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, apartCnt;
int graph[30][30];
bool visited[30][30];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<int> v;
string S;

bool compare(const int &a, const int &b){
    if(a < b) return true; //true면 그대로 유지
    return false;   //false면 교환
}

void bfs(int x, int y){
    int familyCnt = 0;

    apartCnt++;
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        familyCnt++;
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];

            if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
            if(!visited[next_x][next_y] && graph[next_x][next_y]){
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x,next_y));
            }
        }
    }
    v.push_back(familyCnt);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> S;
        for(int j = 0; j < N; j++)
            graph[i][j] = S[j] - '0';
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(!visited[i][j] && graph[i][j]) bfs(i,j);

    sort(v.begin(),v.end(),compare);

    cout << apartCnt;
    for(int i = 0; i < v.size(); i++)
        cout << '\n' << v[i];

    return 0;
}