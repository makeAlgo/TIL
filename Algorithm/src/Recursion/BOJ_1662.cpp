#include <iostream>
#include <utility>
#include <stack>
using namespace std;

string str;
stack<pair<int, int>> s;				// K 위치 저장 idx , Q size

int main(void){
	cin >> str;

	s.push(make_pair(0,0));				// 첫번째 문자열부터 스택에 넣고 시작

	for(int i = 0; i < str.size(); i++){
		if(str[i] == '(') 
			s.push(make_pair(i-1, 0));	// K 위치 idx 저장, 해당 Q size 0으로 초기화
		else if(str[i] == ')'){
			int tmp;					// 압축해제한 Q size 저장
			tmp = (str[s.top().first] - '0') * s.top().second; 
			s.pop();					// 압축해제한 스택 pop
			s.top().second += tmp - 1;	// 압축 해제 후 이전 문자열 길이에 더함
		}
		else
			s.top().second++;			// 해당 Q size 증가
	}

	cout << s.top().second;

	s.pop();
	return 0;
}