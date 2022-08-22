#include <iostream>
#include <string>
using namespace std;

int main(void){
    string A,B;
    
    int min = 0, max = 0;
    for(int i = 0; i < 2; i++){
        cin >> A;

        int pow = 1;
        for(int j = A.size()-1; j >= 0; j--){
            if(A[j] == '5' || A[j] == '6'){
                min += pow * 5;
                max += pow * 6;
            } 
            else{
                min += pow * (A[j]-48);
                max += pow * (A[j]-48);
            }
            pow *= 10;
        }
    }

    cout << min << ' ' << max;

    return 0;
}