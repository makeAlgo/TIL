#include <iostream>

using namespace std;

int main(void){
    int N;
    cin >> N;

    int num = 665, cnt = 0;
    string target;
    while(1){
        num++;
        target = to_string(num);
        for(int i = 2; i < target.size(); i++){
            if(target[i] == '6' && target[i-1] == '6' && target[i-2] == '6'){
                cnt++;
                break;
            }
        }
        if(N == cnt){
            break;
        }
    }

    cout << num << endl;
    return 0;
}