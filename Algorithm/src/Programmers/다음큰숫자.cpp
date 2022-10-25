#include <string>
#include <vector>

using namespace std;
int checkOneCnt(int number){
    int i = 1;
    int cnt = 0;
    while(i <= number){
        if(number & i) cnt++;
        i *= 2;
    }
    return cnt;
}
int solution(int n) {
    int limit = checkOneCnt(n);
    
    for(int i = n+1; ;i++)
        if(limit == checkOneCnt(i)) return i;
    
}