#include <iostream>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dp[50] = {0,1,1};
    for(int i = 3; i < 41; i++)
        dp[i] = dp[i-1] + dp[i-2];

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(num == 0) cout << 1 << ' ' << 0 <<'\n';
        else if(num == 1) cout << 0 << ' ' << 1 <<'\n';
        else cout << dp[num-1] << ' ' << dp[num] <<'\n';
    }
    return 0;
}