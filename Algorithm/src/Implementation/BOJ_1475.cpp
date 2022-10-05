#include <iostream>

using namespace std;

int arr[10];
string S;

int main(void){
    cin >> S;
    for(int i = 0,len = S.size(); i < len; i++)
        arr[S[i] - '0']++;
    
    int num = 0;
    for(int i = 0; i < 10; i++)
        if(i != 6 && i != 9)
            num = max(num,arr[i]);
    
    cout << max(num, (arr[6] + arr[9] +1)/2);
    return 0;
}