#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> pokemon;
    vector<string> name;
    vector<string> target; 
    
    int n, m;  
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp; 
        name.push_back(temp);
        pokemon.insert(make_pair(temp, i+1));
    }

    for (int i = 0; i < m; i++){
        string temp;
        cin >> temp;       

        if(temp[0] >= 65 && temp[0] <= 90)
            target.push_back(to_string(pokemon[temp]));
        else
            target.push_back(name[stoi(temp)-1]);
    }

    for (int i = 0; i < target.size();i++)
        cout << target[i] << '\n';
    return 0;
}