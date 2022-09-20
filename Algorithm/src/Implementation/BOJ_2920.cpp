#include <iostream>
#include <vector>

using namespace std;

void mode(vector<int> v);

int main(void){
    vector<int> v;
    for(int i = 0; i < 8; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    mode(v);
    return 0;
}

void mode(vector<int> v){
    if(v[0] == 1){
        for(int i = 1; i < 8; i++){
            if(v[i-1] > v[i]){
                cout << "mixed" << endl; 
                exit(0);              
            }
        }
        cout << "ascending" << endl;
        
    }
    else if(v[0] == 8){
        for(int i = 1; i < 8; i++){
            if(v[i-1] < v[i]){
                cout << "mixed" << endl; 
                exit(0);
            }
        }
        cout << "descending" << endl;
    }
    else{
        cout << "mixed" << endl; 
        exit(0);
    }
}