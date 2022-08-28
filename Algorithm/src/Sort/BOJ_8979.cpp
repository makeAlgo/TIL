#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct country{
    int idx;
    int gold;
    int silver;
    int bronze;
    int rank;
};

bool compare(country a, country b);

int main(void){
    int N,K;
    cin >> N >> K;
    vector<country> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i].idx >> v[i].gold >> v[i].silver >> v[i].bronze;
    
    sort(v.begin(),v.end(),compare);
    v[0].rank = 1;
    for(int i = 1; i < N; i++){
        if(v[i-1].gold > v[i].gold){
            v[i].rank = i+1;
        }
        else if(v[i-1].gold == v[i].gold){
            if(v[i-1].silver > v[i].silver){
                v[i].rank = i+1;
            }
            else if(v[i-1].silver == v[i].silver){
                if(v[i-1].bronze > v[i].bronze){
                    v[i].rank = i+1;
                }  
                else if(v[i-1].bronze == v[i].bronze){
                    v[i].rank = v[i-1].rank;
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        if(v[i].idx == K)
            cout << v[i].rank;
    }
    return 0;
}

bool compare(country a, country b){
    if(a.gold == b.gold){   
        if(a.silver == b.silver){
            return a.bronze > b.bronze;
        }
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}