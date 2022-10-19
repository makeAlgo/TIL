#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string &a, const string &b){
    if(a + b > b + a) return true; // true면 유지
    return false; // false면 교환
}

string solution(vector<int> numbers) {
    vector<string> v;
    string answer = "";
    
    for(int i = 0; i < numbers.size(); i++)
        v.push_back(to_string(numbers[i]));
    
    sort(v.begin(),v.end(),compare);
    
    for(int i = 0; i < v.size(); i++)
        answer += v[i];
    
    if(answer[0] == '0')
        answer = "0";
    return answer;
}