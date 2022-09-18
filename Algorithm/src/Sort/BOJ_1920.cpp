#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    set<long long> check;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        check.insert(num);
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        int target;
        cin >> target;
        cout << check.count(target) << '\n';
    }

    return 0;
}
