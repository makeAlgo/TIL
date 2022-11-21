#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> answer = {0,1,2};

void dp(){
    long long tmp;
    for(int i = 3; i <= N; i++){
        tmp = 0;
        tmp = answer[i - 1] + answer[i - 2];
        answer.push_back(tmp%15746);
    }
}

int main() {
    cin >> N;
    dp();
    cout << answer[N] % 15746;
}