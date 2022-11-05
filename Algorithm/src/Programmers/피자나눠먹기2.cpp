#include <string>
#include <vector>

using namespace std;

int gcd(int a,int b){
    int c = 0;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int solution(int n) {
    return n/gcd(6,n);
}