/***********************************************
 * 2025-08-05
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin >> board[i][j];
        }
    }
    
    vector<int> temp;
    temp.insert(temp.end(), board[N-1].begin(), board[N-1].end());

    for(int i = N-2; i >= 0; i--){
        vector<int> long_temp;
        long_temp.reserve(2 * N);
        long_temp.insert(long_temp.end(), temp.begin(), temp.end());
        long_temp.insert(long_temp.end(), board[i].begin(), board[i].end());
        sort(long_temp.begin(), long_temp.end(), greater<int>());
        copy(long_temp.begin(), long_temp.begin()+N, temp.begin());

    }

    cout << temp[N-1] << endl; 

    // 알고리즘 문제 풀이 시작
    return 0;
}