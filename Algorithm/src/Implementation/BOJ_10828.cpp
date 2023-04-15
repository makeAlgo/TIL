#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;

int main(void){
	cin >> N;
	vector<int> v;

	while(N--){
		string str;
		int X;
		cin >> str >> X;

		if(str == "push"){
			v.push_back(X);
		}
		else if(str == "pop"){
			if(v.size() == 0) cout << -1 << '\n';
			else {
				cout << v.back() << '\n';
				v.pop_back();
			}
		}
		else if(str == "size"){
			cout << v.size() << '\n';
		}
		else if(str == "empty"){
			if(v.size() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(str == "top"){
			if(v.size() == 0) cout << -1 << '\n';
			else cout << v.back() << '\n';
		}
		else{
			;
		}
	}

	return 0;
}