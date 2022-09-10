#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<tuple<int,int,int>> v;
int n,a,b,c,cnt;
int arr[101];

int main(void)
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a>>b>>c;
        v.push_back(make_tuple(c,b,a));
    }

    sort(v.rbegin(),v.rend());
    
    for(int i=0 ; i < v.size() ; i++){
        if(cnt==3)
            break;
        if(arr[get<2>(v[i])]==2)
            continue;
        cout << get<2>(v[i]) << " " << get<1>(v[i]) << "\n";
        arr[get<2>(v[i])]++;
        cnt++;
    }

    return 0;
}