#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;

int main(void){
	cin >> N;
	vector<int> v;
	while(N--){
		int X;
		string str;
		cin >> str;

		if(str == "push") {
			cin >> X;
			v.push_back(X);
		}
		else if(str == "pop") {
			if(v.size() == 0) cout << -1 << '\n';
			else {
				cout << v.front() << '\n';
				v.erase(v.begin());
			}
		}
		else if(str == "size") {
			cout << v.size() << '\n';
		}
		else if(str == "empty") {
			if(v.size() == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if(str == "front") {
			if(v.size() == 0) cout << -1 << '\n';
			else cout << v.front() << '\n';
		}
		else if(str == "back") {
			if(v.size() == 0) cout << -1 << '\n';
			else cout << v.back() << '\n';
		}
		else {
			;
		}
	}
	return 0;
}