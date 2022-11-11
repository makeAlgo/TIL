#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<int> primes;
    for(int i = 2; i <= n; i++){
        bool isprime = true;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                isprime = false;
                break;
            }
        }
        if(isprime) primes.push_back(i);
    }

    return 0;
}