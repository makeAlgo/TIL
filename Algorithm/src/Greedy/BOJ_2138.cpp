#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int calMinPress(int N, vector<int> a, bool mode);
int compare(int a , int b);

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    string a,b;
    cin >> a;
    cin >> b;

    vector<int> v(N);
    for(int i = 0; i < N; i++){
        if(a[i] == b[i])
            v[i] = 0;
        else
            v[i] = 1;
    }

    int result;
    result = compare(calMinPress(N,v,true),calMinPress(N,v,false));

    cout << result << endl;
 
    return 0;
}

int calMinPress(int N, vector<int> a, bool mode){
    int cnt = 0;
    if(mode == true){
        a[0] = !a[0];
        a[1] = !a[1];
        cnt++;
    }

    for(int i = 1; i < N; i++){
        if(a[i-1] == 1){
            for(int j = i-1; j <= i+1; j++){
                if(j < a.size())
                    a[j] = !a[j];
            }  
            cnt++;
        }
    }

    for(int i = 0; i < N; i++){
        if(a[i] == 1){
            cnt = -1;
        }
    }

    return cnt;
}

int compare(int a , int b){
    if(a < 0 && b >= 0)
        return b;
    else if(a >= 0 && b < 0)
        return a;
    else if(a >= 0 && b >= 0)
        return min(a,b);
    else
        return -1;
}