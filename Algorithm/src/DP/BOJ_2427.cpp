#include <iostream>

using namespace std;

int N;

int fibo(int n){
    int arr[50] = {0,};
    arr[0] = arr[1] = 1;
    
    for(int i = 2; i < n; i++)
        arr[i] = arr[i-1] + arr[i-2];

    return arr[n-1];
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cout << fibo(N);
    return 0;
}