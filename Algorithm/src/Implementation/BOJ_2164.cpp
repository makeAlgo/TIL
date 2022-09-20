#include <iostream>
#include <queue>

using namespace std;

int main(void){
    int N;
    cin >> N;

    queue<int> cards;
    for(int i = 0; i < N; i++){
        cards.push(i+1);
    }

    while(cards.size() > 1){
        cards.pop();
        int tmp = cards.front();
        cards.pop();
        cards.push(tmp);
    }

    cout << cards.front() << endl;

    return 0;
}