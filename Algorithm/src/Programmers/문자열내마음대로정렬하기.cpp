#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int idx;

bool compare(const string &a, const string &b){
    if(a[idx] < b[idx]) return true; //true면 현상유지
    else if(a[idx] == b[idx])
        return a < b; 
    return false; //false면 자리 교환
}

vector<string> solution(vector<string> strings, int n) {
    idx = n;
    sort(strings.begin(),strings.end(),compare);
    return strings;
}