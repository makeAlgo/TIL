#include <iostream>
#include <algorithm>

using namespace std;
bool compare(int a, int b);

int main(void){
    ios::sync_with_stdio(false);    
    cin.tie(NULL);

    int N;
    cin >> N;
    int arr[N*N];

    for(int i = 0; i < N*N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N*N, compare);
    cout << arr[N-1] << endl; 
    return 0;
}

bool compare(int a, int b){
    return a > b;
}