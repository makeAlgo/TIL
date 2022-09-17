#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    vector<long long> tips(100001);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> tips[i];
    
    sort(tips.begin(), tips.end(), greater<int>());

    long long sum = 0;
    for (int i = 0; i < N; i++){
        if(tips[i] - i > 0)
            sum += tips[i] - i;
    }

    cout << sum << endl;
    return 0;
}