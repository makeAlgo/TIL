#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b);

int main(void){
    int N;
    cin >> N;
    
    vector<string> v;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(),v.end(),compare);
        
    for(int i = 0; i < N; i++)
        if(i < N && v[i] == v[i+1]){
            continue;
        }
        else
            cout << v[i] << '\n';
    
    return 0;
}

bool compare(string a, string b){
    if(a.length() < b.length())
        return 1;
    else if(a.length() > b.length())
        return 0;
    else
        return a < b;
}
