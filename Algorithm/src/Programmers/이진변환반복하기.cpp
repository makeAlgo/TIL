#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;    
    int zeroCnt = 0, binaryCnt = 0, len;
    
     while(s != "1")
    {
        string tmp = "";
        int size = 0, num;
        binaryCnt++;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')
                zeroCnt++;
            else
                tmp += "1";
        }
        
        len = tmp.size();
        s = "";
        while(len > 0)
        {
            s += to_string(len % 2);
            len /= 2;
        }
    }
    
    answer.push_back(binaryCnt);
    answer.push_back(zeroCnt);
    
    return answer;
}