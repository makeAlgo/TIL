#include <iostream>
#include <vector>
#include <algorithm>

#define SUM_OF_THE_DWARVES_HEIGHTS 100

using namespace std;

int main(void){
    vector<int> dwarf;
    int sum = 0;

    for(int i = 0; i < 9; i++){
        int tmp;
        cin >> tmp;
        sum += tmp;
        dwarf.push_back(tmp);
    }
    
    sort(dwarf.begin(),dwarf.end());

    int target = sum - SUM_OF_THE_DWARVES_HEIGHTS;
    int lIdx = 0, rIdx = dwarf.size()-1;
    while(1){
        if((dwarf[lIdx] + dwarf[rIdx]) < target)
            lIdx++;
        else if((dwarf[lIdx] + dwarf[rIdx]) > target)
            rIdx--;
        else{
            dwarf.erase(dwarf.begin() + rIdx);
            dwarf.erase(dwarf.begin() + lIdx);
            break;
        }
    }

    for(int i = 0; i < dwarf.size(); i++)
        cout << dwarf[i] <<'\n';

    return 0;
}

/*
7 8 10 13 15 19 20 23 25

후보 9개 2개 제외 한 수들의 합이 100
모든 합 - 100 의 수 = 40
7 + 25 < 40 LEFT_IDX 오른쪽으로 한칸 이동
X + 25 > 40 RIGHT_IDX 왼쪽으로 한칸 이동
X + Y = 40 이면 BREAK !!
*/