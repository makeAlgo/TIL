#include <iostream>
using namespace std;

int T, n;
int d[15];
int main(void){
    //1+1+1+1, 1+2+1, 2+1+1, 3+1 
    //1+1+2, 2+2
    //1+3
    d[1] = 1; d[2] = 2; d[3] = 4;
    for(int i = 4; i <= 11; i++)
        d[i] = d[i-1] + d[i-2] + d[i-3];
    
    cin >> T;
    while(T--){
        cin >> n;
        cout << d[n] << '\n';
    }
    return 0;
}