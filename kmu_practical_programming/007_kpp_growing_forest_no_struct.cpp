/***********************************************
 * 2025-04-25
 * 007_실전프로젝트-숲가꾸기-std
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m, k, p;
        cin >> n >> m >> k >> p; // 격자크기 n, 나무 수 m, 지력 회복 k, 시뮬 반복 횟수 p
        vector<vector<int>> nutrient(n, vector<int>(n));
        vector<vector<vector<int>>> board(n, vector<vector<int>>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> nutrient[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            int r, c, age; // 좌표 (r,c), 나이 age
            cin >> r >> c >> age;
            board[r][c].push_back(age);
        }
        for(int year = 0; year < p; year++){
            vector<vector<int>> dead_nutrient(n, vector<int>(n, 0));
            
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){    
                    vector<int> updated;
                    sort(board[i][j].begin(), board[i][j].end());
                    for(int tree : board[i][j]){
                        if(nutrient[i][j] >= tree){
                            nutrient[i][j] -= tree;
                            tree++;
                            updated.push_back(tree);
                        }
                        else{
                            dead_nutrient[i][j] += tree/2;
                        }
                    }
                    board[i][j] = updated;        
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    nutrient[i][j] += dead_nutrient[i][j];
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    for(int tree : board[i][j]){
                        if(tree % 5 == 0){
                            for(int d = 0; d < 8; d++){
                                int di = i + dx[d]; 
                                int dj = j + dy[d];
                                if(di >= 0 && dj >= 0 && di < n && dj < n){
                                    board[di][dj].push_back(1);
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    nutrient[i][j] += k;
                }
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                result += board[i][j].size();
            }
        }
        cout << result << endl;        
    }
    return 0;
}