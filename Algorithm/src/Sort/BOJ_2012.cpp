#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> v(N);

    for(int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(),v.end());

    long long sum = 0;

    for(int i = 0; i < N; i++) 
        sum += abs((i+1) - v[i]);
    
    cout << sum << endl;
}