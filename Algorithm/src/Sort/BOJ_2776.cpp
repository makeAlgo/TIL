#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T,N,M;
int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T;
    for(int j = 0; j < T; j++){
        cin >> N;
        vector<int> note1;
        for(int i = 0; i < N; i++){
            int num;
            cin >> num;
            note1.push_back(num);
        }
        sort(note1.begin(),note1.end());

        cin >> M;
        for(int i = 0; i < M; i++){
            int target;
            cin >> target;
            if (binary_search(note1.begin(), note1.end(), target))
				cout << 1 << '\n';
			else
				cout << 0 < '\n';
        }
    }
    
    return 0;
}
