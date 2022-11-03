#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<int> answer;
    vector<int> A(N), B(M);
    
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < M; i++)
        cin >> B[i];

    int Aidx = 0, Bidx = 0;
    for(int i = 0 ; i < N+M; i++){
        if(Aidx == N) answer.push_back(B[Bidx++]);
        else if(Bidx == M) answer.push_back(A[Aidx++]);
        else if(A[Aidx] <= B[Bidx]) answer.push_back(A[Aidx++]);
        else answer.push_back(B[Bidx++]);
    }

    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';
    return 0;
}