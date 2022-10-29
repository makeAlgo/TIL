#include <iostream>

using namespace std;

int N;
bool isused[9];
int arr[8];

void func(int k){
    if(k == N){
        for(int i = 0; i < N; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
    for(int i = 1; i <= N; i++){
        if(!isused[i]){
            isused[i] = true;
            arr[k] = i;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main(void){
    cin >> N;
    func(0);

    return 0;
}