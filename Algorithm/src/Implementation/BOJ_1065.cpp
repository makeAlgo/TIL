#include <iostream>

using namespace std;

int main(){
	int n;
    cin >> n;

	int answer;
	if(n < 100) answer = n;
	else{
		answer = 99;
		if (n == 1000) n = 999;

		for (int i = 100; i <= n; ++i) {
            int tmp1 = i % 10;
            int tmp2 = i / 10 % 10;
            int tmp3 = i / 100 % 10;

            if (tmp2 * 2 == tmp1 + tmp3) answer += 1;
            else answer += 0;
	    }
    }

    cout << answer;
	return 0;
}