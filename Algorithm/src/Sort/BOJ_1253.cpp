#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> v;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(),v.end());

    int cnt = 0;
    for(int i = 0; i < N; i++){
        int lIdx = 0;
        int rIdx = N-1;
        while(lIdx < rIdx){
            if(lIdx == i) lIdx++;
            if(rIdx == i) rIdx--;
            if(lIdx == rIdx) break;

            int cal = v[lIdx] + v[rIdx];

            if(cal < v[i])
                lIdx++;
            else if(cal > v[i])
                rIdx--;
            else{
                cnt++;
                break;
            }
            
        }
    }

    cout << cnt;

    return 0;
}