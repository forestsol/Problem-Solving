/***********************************************
 * 2025-08-02
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<vector<char>> start_black(8, vector<char>(8));
vector<vector<char>> start_white(8, vector<char>(8));


int main() {
    fastio;
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < 8; ++i){
        string blackline = "BWBWBWBW";
        string whiteline = "WBWBWBWB";
        if(i%2 == 0){
            for(int j = 0; j <8; ++j){
                start_black[i][j] = blackline[j];
                start_white[i][j] = whiteline[j];
            }   
        }
        else{
            for(int j = 0; j <8; ++j){
                start_black[i][j] = whiteline[j];
                start_white[i][j] = blackline[j];
            }
        }
    }

    vector<vector<char>> orgin_board(N, vector<char>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> orgin_board[i][j];
        }
    }

    int min_count = INT_MAX;

    for(int i = 0; i < N-8+1; i++){
        for(int j = 0; j < M-8+1; j++){
            
            int diff_black = 0;
            int diff_white = 0;
            for(int x = 0; x < 8; x++){
                for(int y = 0; y < 8; y++){
                    if(orgin_board[i+x][j+y] != start_black[x][y]) diff_black++;
                    if(orgin_board[i+x][j+y] != start_white[x][y]) diff_white++;
                }
            }

            int local_min = min(diff_black, diff_white);
            min_count = min(min_count, local_min);

        }
    }
    
    cout << min_count << endl;


    // 알고리즘 문제 풀이 시작
    return 0;
}