#include <iostream>
#include <vector>

using namespace std;
int main(void){
    
    ios::sync_with_stdio(false);    
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> num(10001,0);
    
    for (int i = 0, tmp; i < N; i++){
        cin >> tmp;
        num[tmp]++;
    }
    
    for(int i = 0; i < 10001; i++){
        for(int j = 0; j < num[i]; j++)
            cout << i << '\n';
    }
    return 0;
}
