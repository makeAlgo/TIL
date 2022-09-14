#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    long long tips[100001];
    int n;
    cin >> n;

    for (int i = 0; i < n;i++)
        cin >> tips[i];
    
    sort(tips, tips + n, greater<int>());

    long long sum = 0;
    for (int i = 0; i < n;i++){
        if(tips[i] - i > 0)
            sum += tips[i] - i;
    }

    cout << sum;
    return 0;
}