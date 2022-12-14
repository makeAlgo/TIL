#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {   
    int days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    string day[8] = {"THU","FRI","SAT","SUN","MON","TUE","WED","THU"};
    
    int sumOfDays = 0;
    for(int i = 1; i < a; i++)
        sumOfDays += days[i];
    sumOfDays += b;
        
    return day[sumOfDays%7];
}