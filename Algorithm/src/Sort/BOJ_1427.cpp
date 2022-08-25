#include <iostream>
#include <vector>
using namespace std;

int main(void){
    string N;
    cin >> N;
    vector<int> cnt(10,0);
    for(int i = 0; i < N.length(); i++)
        cnt[N[i]-48]++;

    for(int i = 9; i >= 0; i--){
        while(cnt[i] != 0){
            cout << i;
            cnt[i]--;
        }
    }

    return 0;
}
