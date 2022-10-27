#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
bool isused[105];
bool isusedT[205];

bool compare(const int &a, const int &b){
    if(a < b) return true; //true면 현상유지
    return false; //false면 자리교환
}

void func(int k, int num, int target, const vector<int> &v){ //현재까지 k개 선택
    if(k == 2){ //2개 선택했다면
        if(!isusedT[target]){
            isusedT[target] = true;
            answer.push_back(target);
        }
        return;
    }
    for(int i = num; i < v.size(); i++){
        if(!isused[i]){
            isused[i] = true;
            func(k+1, i, target+v[i], v);
            isused[i] = false;
        }
    }
}

vector<int> solution(vector<int> numbers) {
    func(0,0,0,numbers);
    sort(answer.begin(),answer.end(),compare);
    return answer;
}