#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
    투포인터
    rIdx가 움직이면서 sum에 더함
    sum이 k보다 커지면 sum에서 lIdx값 빼고 lIdx 1증가
    
    구조체 사용
    sum이 k랑 맞을 때 lIdx, rIdx 입력
    수열길이 저장
    
    정렬
    수열길이 기준 오름차순으로 정렬
    수열길이가 같을 때 lIdx 기준 오름차순으로
*/

struct matching{
    int lIdx;
    int rIdx;
    int size;
};

bool compare(const matching& a, const matching& b){
    if(a.size == b.size)
        return a.lIdx < b.lIdx;
    return a.size < b.size;
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<matching> cal;
    int sum = 0, lIdx = 0;
    
    for(int rIdx = 0; rIdx < sequence.size(); rIdx++) {
        sum += sequence[rIdx];
        while(sum > k) {
            sum -= sequence[lIdx++];
        }
        
        if(sum == k) {
            matching tmp;
            tmp.lIdx = lIdx;
            tmp.rIdx = rIdx;
            tmp.size = rIdx - lIdx + 1;
            cal.push_back(tmp);
        }
    }
    
    sort(cal.begin(),cal.end(),compare);

    answer.emplace_back(cal[0].lIdx);
    answer.emplace_back(cal[0].rIdx);
    return answer;
}