#include <string>
#include <vector>
#include <bitset>

using namespace std;
bool graph[20][20];

void func(const vector<int> &arr, const int &n){
    for(int i = 0; i < arr.size(); i++){
        bitset<20> bit(arr[i]);
        for(int j = 0; j < n; j++)
            if(bit[n-1-j] == 1) graph[i][j] = 1;
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    func(arr1, n);
    func(arr2, n);
    
    for(int i = 0; i < n; i++){
        string S = "";
        for(int j = 0; j < n; j++){
            if(graph[i][j]) S += '#';
            else S += ' ';
        }
        answer.push_back(S);
    }
            
    return answer;
}