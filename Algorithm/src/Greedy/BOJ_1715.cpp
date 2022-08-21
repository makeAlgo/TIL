#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;  

    int N;
    cin >> N;    
    for(int i = 0, num; i < N; i++)
    {
        cin >> num;
        pq.push(num);
    }

    int sum = 0;
    for(int i = 0, num, tmp; i < N-1; i++)
    {
        num = pq.top();
        pq.pop();
        tmp = num + pq.top();
        pq.pop();
        
        sum += (tmp);
        pq.push(tmp);
    }
    
    cout << sum << endl;

    return 0;
}