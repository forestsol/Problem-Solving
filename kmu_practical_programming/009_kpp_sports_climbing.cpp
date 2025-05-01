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
            int y = q.front().second; // y는 좌 우
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

            // 좌우 2칸, 3칸.
            for(int d : { -3, -2, 2, 3 }){
                int ny = y + d;
                if(ny < 0 || ny >= n) continue; // 클라이밍 판 밖이면 넘어감
                if(grid[x][ny] != 'H') continue; // 홀드 아니면 넘어감

                bool canJump = true;
                int from = min(y, ny); // 항상 증가하는 방향으로 돌면서 목적지와 자신 사이의 칸을 검사하기 위해 시작점은 최솟값 사용.
                int to = max(y, ny); // 도착점은 최댓값을 사용 (동일한 이유)
                for(int k = from + 1; k < to; k++){
                    if(grid[x][k] != '.' || x - 1 < 0 || grid[x - 1][k] != '.'){ // grid[x][k] != '.' 점프 도중 가로 경로가 빈칸. // x - 1 < 0 제일 윗줄에서는 가로 3칸 점프 불가 // 가로 경로 바로 윗칸도 전부 빈칸
                        canJump = false;
                        break;
                    }
                }
                if(x-1 >= 0 && grid[x-1][y] == '.' && grid[x-1][ny] == '.' && canJump){ // x-1 >= 0 제일 윗 줄인지 검사 // grid[x-1][y] == '.' 자신의 위가 비었는지 검사 // 도착지 위가 비었는지 검사
                    if (dist[x][ny] == -1) {
                        dist[x][ny] = dist[x][y] + 1;
                        q.push({ x, ny });
                    }
                }
            }

            // 위 2칸.
            if(x-2 >= 0 && grid[x-1][y] == '.' && grid[x-2][y] == 'H' && dist[x-2][y] == -1){ // 1. 위로 두칸이 0보다 커야함. // 한칸 위는 빈칸 // 두칸 위는 홀드 // 그리고 거리를 위해 dist가 -1
                dist[x-2][y] = dist[x][y] + 1;
                q.push({x-2, y});
            }

            // 좌상단
            if(x-1 >= 0 && y-1 >= 0 && grid[x][y-1] == '.' && grid[x-1][y] == '.' && grid[x-1][y-1] == 'H'){
                if(dist[x-1][y-1] == -1){
                    dist[x-1][y-1] = dist[x][y] + 1;
                    q.push({x-1, y-1});
                }
            }
            
            // 우상단
            if(x-1 >= 0 && y+1 < n && grid[x][y+1] == '.' && grid[x-1][y] == '.' && grid[x-1][y+1] == 'H'){
                if(dist[x-1][y+1] == -1){
                    dist[x-1][y+1] = dist[x][y] + 1;
                    q.push({x-1, y+1});
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'H'){
                    cout << (dist[i][j] == -1 ? -1 : dist[i][j]) << " ";
                }
                else{
                    cout << "0 ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}