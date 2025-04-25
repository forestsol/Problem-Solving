/***********************************************
 * 2025-04-17
 * 007_실전프로젝트-숲가꾸기-std
 * 시뮬레이션 구현 문제
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

struct Tree{
    int age;
    bool alive;
};

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m, k, p;
        cin >> n >> m >> k >> p; // 총 격자의 크기 n, 나무의 수 m, 지력 회복 크기 k, 시뮬레이션 반복 횟수 p
        vector<vector<int>> nutrient(n, vector<int>(n)); // 남은 지력
        vector<vector<vector<Tree>>> board(n, vector<vector<Tree>>(n)); // 나무 상태
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> nutrient[i][j]; // 지력 초기값 입력
            }
        }

        for(int i = 0; i < m; i++){
            int r, c, o; // 나무의 좌표 <r, c> , 나무의 나이 o
            cin >> r >> c >> o;
            board[r][c].push_back({o, true}); // 나무의 위치에 나무의 상태 넣기.(나이와 생존)
        }
        
        // --- 시뮬레이션

        for(int year = 0; year < p; year++){

            // --- 나무의 성장 및 죽음 (1, 2번 규칙)
            vector<vector<int>> dead_nutrient(n, vector<int>(n, 0)); // 죽은 나무들이 남긴 영양분을 기록할 복사본 벡터.

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    sort(board[i][j].begin(), board[i][j].end(), [](Tree a, Tree b)->bool {return a.age < b.age;}); // 해당 위치의 나무들을 나이순으로 정렬

                    vector<Tree> updated;
                    // 나이가 업데이트된 나무는 여기 넣어두고, 삭제된 나무는 여기에 넣지 않음
                    // 임시저장용 벡터
                    // 추후 이걸 사용하여 board[i][j]를 업데이트.
                    // 복사본을 사용하는 이유 : 순회할 때 원본을 수정하면 오류가 생길 수도 있기 때문

                    for(Tree tree : board[i][j]){ // 해당위치의 나무를 쭉 검사. 
                        if(nutrient[i][j] >= tree.age ){ // 나무의 나이보다 지력이 커야, 나무가 먹을 수 있음.
                            nutrient[i][j] -= tree.age; // 나무가 먹은만큼 지력이 줄어듬
                            tree.age++; // 나무는 나이가 1 증가.
                            updated.push_back(tree); // 수정된 구조체를 업데이트된 벡터에 넣어두기.
                        }
                        else{
                            dead_nutrient[i][j] += tree.age/2; // 남은 지력이 나무의 나이보다 작으면 나무가 죽어버림.
                        }
                    }
                    board[i][j] = updated;
                }
            }
            for(int i = 0; i < n; i++){ // 죽은 나무의 지력을 전체 지력에 갱신
                for(int j =0; j < n; j++){
                    nutrient[i][j] += dead_nutrient[i][j];
                }
            }
            // --- 1, 2 규칙 끝
            
            // --- 나무 번식 3번 규칙
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    for(Tree tree : board[i][j]){
                        if(tree.age % 5 == 0){
                            for(int d=0; d<8; d++){
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if(ni >= 0 && nj >= 0 && ni < n && nj < n){
                                    board[ni][nj].push_back({1, true});
                                }
                            }
                        }
                    }
                }
            }

            // --- 3 규칙 끝

            // --- 지력 자체 회복 4번 규칙

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    nutrient[i][j] += k;
                }
            }

            // --- 4 규칙 끝
        }
        int total = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                total += board[i][j].size(); // vector.size() 로 들어있는 나무 수 반환
            }
        }
        cout << total << endl;  // 시뮬레이션 결과 남아있는 나무 수 출력.
    }
    return 0;
}