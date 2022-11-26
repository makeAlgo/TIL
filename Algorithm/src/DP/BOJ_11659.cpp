#include <iostream>

using namespace std;

int n, m;
int num[100002];
int sum[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> num[i];
        
        if(i == 0)
            sum[i] = num[i];
        else
            sum[i] = sum[i-1] + num[i];
    }
 
    while (m--){
        int a, b;
        cin >> a >> b;

        if(a-2 >= 0)
            cout << sum[b-1] - sum[a-2] << '\n';
        else
            cout << sum[b-1] << '\n';
    }

    return 0;
}