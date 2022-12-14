#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = 0, h = 0;
    int mx = -1, mn = 1001;
    
    for(int i = 0; i < sizes.size(); i++){
        mx = max(sizes[i][0],sizes[i][1]);
        mn = min(sizes[i][0],sizes[i][1]);

        w = max(w, mx);
        h = max(h, mn);
    }
        
    return w*h;
}