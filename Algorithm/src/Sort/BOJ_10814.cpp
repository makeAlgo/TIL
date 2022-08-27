#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct info{
    int age;
    string name;
    int priority;
};

bool compare(info a, info b);

int main(void){
    int N;
    cin >> N;

    vector<info> vec;

    for(int i = 0; i < N; i++){
        int age;
        string name;
        cin >> age >> name;
        vec.push_back({age, name, i});
    }

    sort(vec.begin(),vec.end(),compare);
    for(int i = 0; i < N; i++)
        cout << vec[i].age << ' ' << vec[i].name << '\n';
    
    return 0;
}

bool compare(info a, info b){
    if(a.age == b.age)
        return a.priority < b.priority;
    else
        return a.age < b.age;
}