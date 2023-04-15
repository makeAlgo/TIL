#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v = {-99999};

bool compare(const int&a, const int&b){
	return a < b;
}

int main(void){
	cin >> N;

	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(),v.end(),compare);

	int lIdx = 0;
	for(int rIdx = 1; rIdx <= N; rIdx++) {
		if(v[lIdx] != v[rIdx]) {
			cout << v[rIdx] << ' ';
			lIdx = rIdx;
		}
	}

	return 0;
}