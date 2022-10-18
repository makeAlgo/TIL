#include <string>
#include <vector>

using namespace std;

int N, M;
int cnt;
bool isused[21];

void func(int num, int k, int check, const vector<int> &numbers, const int &target){ //현재까지 k개 선택
    if(k == M){ //M개 선택했다면
        if(check == target) cnt++;
        return;
    }
    for(int i = num; i < N; i++){
        if(!isused[i]){
            isused[i] = true;
            if(check-2*numbers[i] < target) continue;
            func(i+1, k+1, check-2*numbers[i], numbers, target);
            isused[i] = false;
        }
    }
}


int solution(vector<int> numbers, int target) {
    int sum = 0;
    N = numbers.size();
    
    for(int i = 0; i < N; i++)
        sum += numbers[i];
    
    for(int i = 1; i <= N; i++){
        M = i;
        func(0, 0, sum, numbers, target);
    }

    return cnt;
}