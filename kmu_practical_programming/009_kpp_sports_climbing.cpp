/***********************************************
 * 2025-05-01
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};



int main() {
    fastio;

    int t;
    cin >> t;
    while(t-- > 0){
        int n;
        cin >> n;

        vector<vector<char>> grid(n, vector<char>(n));
        vector<vector<int>> dist(n, vector<int>(n, -1));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }

        queue<pair<int,int>> q;

        if(grid[n-1][0] == 'H'){
            dist[n-1][0] = 1;
            q.push({n-1, 0});
        }

        while(!q.empty()){
            int x = q.front().first; // x는 상 하
            int y = q.front().second; // y는 좌 우우
            q.pop();

            // 상하좌우
            for(int dir = 0; dir < 4; ++dir){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n
                && grid[nx][ny] == 'H'&& dist[nx][ny] == -1 ){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }

            for(int d : { -3, -2, 2, 3 }){
                int ny = y + d;
                if(ny < 0 || ny >= n) continue;
                if(grid[x][y] != 'H') continue;

                bool canJump = true;
                int from  =
            }
        }
    }

    return 0;
}