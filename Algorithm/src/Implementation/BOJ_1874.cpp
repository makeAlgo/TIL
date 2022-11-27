#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> st;
vector<char> v;
int n;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int num = 1;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;

		while(num <= x){
			v.push_back('+');
			st.push(num);
			num++;
		}

		if(x == st.top()){
			st.pop();
			v.push_back('-');
		}
		else{
			cout << "NO";
			return 0;
		}
	}

	for(int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
    return 0;
}