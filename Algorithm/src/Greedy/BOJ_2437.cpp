#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    vector<int> weight;
    int N;
    cin >> N;

    for(int i = 0,tmp; i < N; i++){
        cin >> tmp;
        weight.push_back(tmp);
    }

    sort(weight.begin(), weight.end());
    
    long long sum = 0;
    for(int i = 0; i < N; i++){
        if(weight[i] > sum+1)
            break;
        sum += weight[i];
    }
    cout << sum + 1 << endl;
    return 0;
}