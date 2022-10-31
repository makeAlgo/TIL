#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

bool BS(const vector<int> &v, int target){
    int st = 0;
    int en = N-1;
    while(st <= en){
        int mid = (st + en)/2;
        if(v[mid] == target) return true;
        else if(v[mid] < target)
            st = mid + 1;
        else
            en = mid - 1;
    }
    return false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    vector<int> v(N);
    for(int i = 0 ; i < N; i++)
        cin >> v[i];

    sort(v.begin(),v.end());

    cin >> M;
    for(int i = 0; i < M; i++){
        int target;
        cin >> target;
        cout << BS(v, target) << '\n';
    }

    return 0;
}