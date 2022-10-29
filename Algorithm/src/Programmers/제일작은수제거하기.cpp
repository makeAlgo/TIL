#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int idx = 0;
    
    for(int i = 1, min = arr[0], len = arr.size(); i < len; i++){
        if(arr[i] < min){
            min = arr[i];
            idx = i;
        }
    }
    
    arr.erase(arr.begin() + idx);
    
    return arr.empty() ? vector<int> (1,-1) : arr;
}