#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    string num1, num2;
    cin >> num1 >> num2;

    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    cout<< max(num1,num2) << endl;
    return 0;
}