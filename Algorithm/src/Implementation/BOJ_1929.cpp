#include <iostream>

using namespace std;

int M, N;

bool isPrime(int num){
    if(num == 1) return 0;
    for(int i = 2; i*i <= num; i++)
        if(num % i == 0) return 0;
    return 1;
}

int main(void){
    cin >> M >> N;
    for(int i = M; i < N; i++)
        if(isPrime(i)) cout << i << '\n';    
    return 0;
}