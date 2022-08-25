#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N;
    cin >> N;
    
    vector<int> v;
    for(int i = 0,tmp; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(),v.end());
    
    for(int i = 0; i < N; i++)
        cout << v[i] << '\n';
        

    return 0;
}