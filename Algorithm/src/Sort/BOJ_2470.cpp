#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void){
    int N;
    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    
    sort(v.begin(),v.end());

    int min = 2000000000;
    int lIdx = 0;
    int rIdx = N-1;
    int a, b;
    while(lIdx < rIdx){
        int sum = v[lIdx] + v[rIdx];
        if(min > abs(sum)){
            min = abs(sum);
            a = v[lIdx];
            b = v[rIdx];
        }
        if(sum == 0) 
            break;
        else if(sum < 0) 
            lIdx++;
        else 
            rIdx--;
    }

    cout << a << ' ' << b << endl;
    return 0;
}
