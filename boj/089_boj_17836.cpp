/***********************************************
 * 2025-09-29
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int map_max = 100;
int n, m, t;
int my_map[map_max][map_max];
int dist[map_max][map_max];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int bfs(int X, int Y){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = -1;

    dist[X][Y] = 0;
    queue<pair<int, int>> q;
    q.push({X, Y});

    int weapon_value = INT_MAX;
    int common_value = INT_MAX;

    while(!q.empty()){
        auto [cx, cy] = q.front(); q.pop();

        if(my_map[cx][cy] == 2){
            weapon_value = min(weapon_value, dist[cx][cy] + (n-1-cx) + (m-1-cy));
        }

        for(int i=0; i<4; ++i){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(my_map[nx][ny] != 1 && dist[nx][ny] == -1){
                    dist[nx][ny] = dist[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    if(dist[n-1][m-1] != -1){
        common_value = dist[n-1][m-1];
    }

    return min(weapon_value, common_value);
}

int main() {
    fastio;
    cin >> n >> m >> t;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> my_map[i][j]; 
        }
    }

    int result = bfs(0, 0);

    if(result > t){
        cout << "Fail" << endl;
    }else{
        cout << result << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}