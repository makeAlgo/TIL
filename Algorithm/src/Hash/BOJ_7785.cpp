#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string name;
string log_;
set<string,greater<>> s; 

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name >> log_;
        if(log_ == "enter") s.insert(name);
        else if(log_ == "leave") s.erase(name);
    }
    vector<string> v(s.begin(),s.end());
    sort(v.begin(),v.end(),greater<string>());

    for(auto it : v)
        cout << it << '\n';
    return 0;
}