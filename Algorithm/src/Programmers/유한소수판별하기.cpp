#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    int c = 0;
    while(b){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int solution(int a, int b) {
    b /= gcd(a,b);
    
    for(int i : {2,5})
        while(b%i == 0) b /= i;
    
    return b==1 ? 1 : 2;
}