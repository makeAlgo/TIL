#include <iostream>
#include <queue>

using namespace std;

int N, M, K;  
bool graph[105][105];
bool isused[105][105];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int bfs(int x, int y){
	int cnt = 0;
	isused[x][y] = true;
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	
	while(!q.empty()){
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		cnt++;
		
		for(int i = 0; i < 4; i++){
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			
			if(1 > next_x || 1 > next_y || next_x > N || next_y > M) continue;
			if(!isused[next_x][next_y] && graph[next_x][next_y]){
				isused[next_x][next_y] = true;
				q.push(make_pair(next_x,next_y));
			}
		}
	}
	return cnt;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> K;
	
	for(int i = 0; i < K; i++){
		int r, c;
		cin >> r >> c;
		graph[r][c] = true;
	}
	
	int mx = -1;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			if(!isused[i][j] && graph[i][j])
				mx = max(bfs(i,j),mx);
				
	cout << mx;
	return 0;
}
