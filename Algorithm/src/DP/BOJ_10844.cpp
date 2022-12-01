#include<iostream>

using namespace std;

int n;
int dp[101][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++) {
            if(j == 0)
                dp[i][j] = dp[i - 1][j + 1] % 1000000000;
            else if(j == 9)
                dp[i][j] = dp[i - 1][j - 1] % 1000000000;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++)
        ans = (ans+ dp[n][i]) % 1000000000;
    cout << ans;
    return 0;
}