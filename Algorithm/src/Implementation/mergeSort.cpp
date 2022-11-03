#include <iostream>
#include <algorithm>
using namespace std;

int n = 10;
int arr[101] = {1,2,4,7,3,5,9,6,8,4};
int tmp[101];

void merge(int st, int en){
    int mid = (st+en)/2;

    int idx1 = st, idx2 = mid;
    for(int i = st; i < en; i++){
        if(idx1 == mid) tmp[i] = arr[idx2++];
        else if(idx2 == en) tmp[i] = arr[idx1++];
        else if(arr[idx1] <= arr[idx2]) tmp[i] = arr[idx1++];
        else tmp[i] = arr[idx2++];
    }

    for(int i = st ; i < en; i++)
        arr[i] = tmp[i];
}

void merge_sort(int st, int en){
    if(en == st+1) return;

    int mid = (st+en)/2;  
    merge_sort(st,mid);
    merge_sort(mid,en);
    merge(st,en);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    merge_sort(0, n); //st 부터 en까지
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}