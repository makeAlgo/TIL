#include <string>
#include <vector>
using namespace std;

bool isused[1005];
int answer;

void func(int k, int num, int target, const vector<int> &v){ //현재 k개 선택
    if(k == 3){ //3개 뽑았다면
        if(target == 0) answer++;      
        return;
    }
    for(int i = num; i < v.size(); i++){
        if(!isused[i]){
            isused[i] = true;
            func(k+1, i+1, target + v[i], v);
            isused[i] = false;
        }
    }
}

int solution(vector<int> number) {    
    func(0,0,0,number);
    return answer;
}