#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

    int N, M;
    cin >> N;
    vector<int> crane(N);
    for(int i = 0; i < N; i++)
        cin >> crane[i];

    cin >> M;
    vector<int> box(M);
    for(int i = 0; i < M; i++)
        cin >> box[i];

    sort(crane.begin(),crane.end(),greater<int>());
    sort(box.begin(),box.end(),greater<int>());

    if(crane[0] < box[0]){
        cout << -1 << endl;
        exit(0);
    }

    int cnt = 0;
    while(!box.empty()){
        for(int i = 0; i < crane.size(); i++){
            for(int j = 0; j < box.size(); j++){
                if(crane[i] >= box[j]){
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}