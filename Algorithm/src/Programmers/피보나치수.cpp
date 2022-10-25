#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> v;
    
    v.push_back(0);
    v.push_back(1);

    for(int i = 2; i <= n; i++){
        long long tmp = v[i-2] + v[i-1];
        if(tmp > 1234567) tmp %= 1234567;
        v.push_back(tmp);
    }
    
    answer = v.back() % 1234567;
    return answer;
}