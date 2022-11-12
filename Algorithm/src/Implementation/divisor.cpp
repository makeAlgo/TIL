#include <iostream>
#include <vector>

using namespace std;

vector<int> div;

//최대공약수
int gcd(int a, int b){
    int c;
    while(b){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(void){
    int n;
    cin >> n;

    //약수구하기
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0) div.push_back(i);
    }
    for(int i = (int)div.size()-1; i >= 0; i--){ //.size()가 unsigned 라서 -1 하면 값이 매우 커지는 것 고려 -> (int)
        if(div[i]*div[i] == n) continue;
        div.push_back(n/div[i]);
    }

    return 0;
}