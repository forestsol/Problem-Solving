#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& map){
    queue<pair<int, int>> q;
    q.push({0 ,0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M){
                continue;
            }

            if (map[nx][ny] != 1){
                continue;
            }

            map[nx][ny] = map[x][y] + 1;
            q.push({nx, ny});
        }
    }
}


int main() {
    fastio;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        string line;
        cin >> line;
        for (int j = 0; j < M; j++){
            map[i][j] = line[j] - '0';
        }
    }

    bfs(map);
    
    cout << map[N-1][M-1] << endl;

    return 0;
}