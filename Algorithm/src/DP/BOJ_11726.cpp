#include <iostream>

using namespace std;

int n;
int numOfRect[1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    numOfRect[1] = 1;
    numOfRect[2] = 2;

    for(int i = 3; i <= n; i++) numOfRect[i] = (numOfRect[i-1] + numOfRect[i-2]) % 10007;
    
    cout << numOfRect[n];

    return 0;
}