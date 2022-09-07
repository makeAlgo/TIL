#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void){
    priority_queue<int,vector<int>> pq;

    for(int i = 0; i < 3; i++){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    pq.pop();
    cout << pq.top() << '\n';
    return 0;
}