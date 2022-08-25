#include <iostream>
#include <queue>

using namespace std;

int main(void){
    int N;
    cin >> N;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0,tmp; i < N; i++){
        cin >> tmp;
        pq.push(tmp);
    }
    while(pq.size() != 0){
        cout << pq.top() << '\n'; pq.pop();
    }
    return 0;
}