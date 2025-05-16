/***********************************************
 * 2025-04-27
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m; // 맵 크기 n, 시간 m
        cin >> n >> m;
        int a, b; // 시체 수 a, 치유 와드 수 b
        cin >> a >> b;

        vector<pair<int, int>> corpses(a);
        vector<pair<int, int>> wards(b);

        for(int i = 0; i < a; i++){
            cin >> corpses[i].first >> corpses[i].second;
        }

        for(int i = 0; i < b; i++){
            cin >> wards[i].first >> wards[i].second;
        }

        vector<vector<int>> board(n, vector<int>(n, 0));

        for (auto& corpse : corpses){
            int cx = corpse.first, cy = corpse.second;
            board[cx][cy] += -m; // 자신의 위치에 시간만큼 더하기
            for (int x = 0; x<n; x++){ // 모든 맵을 순회
                for( int y = 0; y<n; y++){
                    if (x == cx && y == cy) continue; // 자기 자신의 자리는 건너뛰기
                    int distance = max(abs(cx-x), abs(cy-y)); //
                    if(distance <= m){
                        board[x][y] += -(m - distance + 1);
                    }
                }
            }
        }
        for (auto& ward : wards){
            int wx = ward.first, wy = ward.second;
            board[wx][wy] += m;
            for (int x = 0; x<n; x++){
                for( int y = 0; y<n; y++){
                    if (x == wx && y == wy) continue;
                    int distance = abs(wx-x) + abs(wy-y);
                    if(distance <= m){
                        board[x][y] += (m - distance + 1);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j];
                if(j != n - 1) cout << " ";
            }
            cout << "\n";
        }
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}