#include <string>
#include <vector>

using namespace std;

int tmp[150];

void merge(int st, int en, vector<int> &v){

    int mid = (st+en)/2;
    
    int lidx = st, ridx = mid;
    for(int i = st; i < en; i++){
        if(lidx == mid) tmp[i] = v[ridx++];
        else if(ridx == en) tmp[i] = v[lidx++];
        else if(v[lidx] <= v[ridx]) tmp[i] = v[lidx++];
        else tmp[i] = v[ridx++];
    }
    
    for(int i = st; i < en; i++)
        v[i] = tmp[i];
}

void merge_sort(int st, int en, vector<int> &v){
    if(en == st+1) return;
    
    int mid = (st+en)/2;
    
    merge_sort(st,mid,v);
    merge_sort(mid,en,v);
    merge(st,en,v);
}

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for(int i = 0; i < my_string.size(); i++)
        if(my_string[i] >= '0' && my_string[i] <= '9')
            answer.push_back(my_string[i] - '0');
    
    merge_sort(0, answer.size(), answer);
    
    return answer;
}