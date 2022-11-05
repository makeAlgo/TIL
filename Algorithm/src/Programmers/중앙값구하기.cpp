#include <string>
#include <vector>
using namespace std;

int tmp[105];

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
    
    merge_sort(st, mid, v);
    merge_sort(mid, en, v);
    merge(st,en,v);
}


int solution(vector<int> array) {    
    merge_sort(0,array.size(), array);
    
    int mid = array.size()/2;
    return array[mid];
}