#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][1001];
int graph[1001][1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dp[i][j] = graph[i][j] + max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));

	cout << dp[N-1][M-1] << endl;
	return 0;
}