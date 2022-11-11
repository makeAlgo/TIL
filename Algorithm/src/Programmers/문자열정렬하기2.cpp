#include <string>
#include <vector>

using namespace std;

char tmp[150];

void merge(int st, int en, string &S){
    int mid = (st+en)/2;
    
    int lidx = st, ridx = mid;
    for(int i = st; i < en; i++){
        if(lidx == mid) tmp[i] = S[ridx++];
        else if(ridx == en) tmp[i] = S[lidx++];
        else if(S[lidx] <= S[ridx]) tmp[i] = S[lidx++];
        else tmp[i] = S[ridx++];
    }
    
    for(int i = st; i < en; i++)
        S[i] = tmp[i];
}

void merge_sort(int st, int en, string &S){
    if(en == st+1) return;
    
    int mid = (st+en)/2;
    
    merge_sort(st,mid,S);
    merge_sort(mid,en,S);
    merge(st,en,S);
}


string solution(string my_string) {
    for(int i = 0; i < my_string.size(); i++)
        my_string[i] = tolower(my_string[i]);
    
    merge_sort(0, my_string.size(), my_string);
    
    return my_string;
}