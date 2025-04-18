/***********************************************
 * 2025-04-18
 * 011_실전프로젝트-치유와드-std
 * 타임 오버 유도 문제 ㅠㅠㅠ
 * 교수님의 풀이를 이해할 수 있도록 하기
 * 문제가 뭔가 알고리즘도 없고 심플해 보인다면, 타임오버 등의 함정이 있을 수도 있음을 고려해봐야 함.
 * 독은 자신을 중심으로 상 하 좌 우 대각선 모두를 색칠하면 됨.
 * 와드는 자신을 중심으로 상 하 좌 우 를 색칠하면 됨.
 ***********************************************/


#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m; // 안전지대의 크기 n, 시간 m
        cin >> n >> m;

        vector<vector<int>> map(n, vector<int>(n, 0)); // 맵

        int a, b; // 시체 수 a, 와드 수 b (<= n)
        cin >> a >> b;
        vector<vector<vector<int>>> dead(n, vector<vector<int>>(n,vector<int>(a, 0))); // z축은 겹치는 와드를 찾기 위한 것
        vector<vector<vector<int>>> ward(n, vector<vector<int>>(n,vector<int>(b, 0)));
        for(int i = 0; i < a; i++){
            int x, y;
            cin >> x >> y;
            dead[x][y][a] = 1;
        }

        for(int j = 0; j < b; j++){
            int x, y;
            cin >> x >> y;
            ward[x][y][b] = 1;
        }

        for(int time = 1; time <= m; time++){

            // 현재 시점에서 정산 및 다음거 색칠
            for(int allnumz = 0; allnumz < a; allnumz++){
                for(int allnumx = 0; allnumx < n; allnumx++){
                    for(int allnumy = 0; allnumy < n; allnumy++){
                        
                        if(dead[allnumx][allnumy][allnumz] == time){
                            map[allnumx][allnumy] -= 1;       
                            for(int c = 0; c < 8; c++){
                                int nx = allnumx + dx[c];
                                int ny = allnumy + dx[c];
                                if(0 <= nx && nx < n && 0 <= ny && ny < n){

                                }

                            }
                        }

                        if(ward[allnumx][allnumy][allnumz] == time){
                            map[allnumx][allnumy] += 1;
                            for(int d = 0; d < 4; d++){

                            }
                        }
                    }
                }
            }


            

             // 색칠
            
                
            //     if(nx >= n) continue;
            //     if(nx < 0) continue;
            //     if(ny >= n) continue;
            //     if(ny < 0) continue;
            //     dead[nx][ny] = time;
            // }

        }
        // 결과 출력
        for(int k = 0; k < n; k++){
            for(int l = 0; l < n; l++){
                cout << map[k][l];
                if(l != n-1) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}