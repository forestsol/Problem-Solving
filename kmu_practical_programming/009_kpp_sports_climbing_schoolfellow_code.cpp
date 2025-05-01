#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm> // min, max 함수 사용을 위해 필요

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<vector<char>> grid(n, vector<char>(n));
        vector<vector<int>> dist(n, vector<int>(n, -1));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> grid[i][j];

        queue<pair<int, int>> q;

        if (grid[n - 1][0] == 'H') {
            dist[n - 1][0] = 1;
            q.push({ n - 1, 0 });
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // 1. 상하좌우
            for (int dir = 0; dir < 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 'H' && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({ nx, ny });
                }
            }

            // 2. 좌우 점프 2~3칸
            for (int d : { -3, -2, 2, 3 }) {
                int ny = y + d;
                if (ny < 0 || ny >= n) continue;
                if (grid[x][ny] != 'H') continue;

                bool canJump = true;
                int from = std::min(y, ny), to = std::max(y, ny);
                for (int k = from + 1; k < to; ++k) {
                    if (grid[x][k] != '.' || x - 1 < 0 || grid[x - 1][k] != '.') {
                        canJump = false;
                        break;
                    }
                }

                if (x - 1 >= 0 && grid[x - 1][y] == '.' && grid[x - 1][ny] == '.' && canJump) {
                    if (dist[x][ny] == -1) {
                        dist[x][ny] = dist[x][y] + 1;
                        q.push({ x, ny });
                    }
                }
            }

            // 3. 위로 2칸
            if (x - 2 >= 0 && grid[x - 1][y] == '.' && grid[x - 2][y] == 'H' && dist[x - 2][y] == -1) {
                dist[x - 2][y] = dist[x][y] + 1;
                q.push({ x - 2, y });
            }

            // 4. 좌상단
            if (x - 1 >= 0 && y - 1 >= 0 && grid[x][y - 1] == '.' && grid[x - 1][y] == '.' && grid[x - 1][y - 1] == 'H') {
                if (dist[x - 1][y - 1] == -1) {
                    dist[x - 1][y - 1] = dist[x][y] + 1;
                    q.push({ x - 1, y - 1 });
                }
            }

            // 5. 우상단
            if (x - 1 >= 0 && y + 1 < n && grid[x][y + 1] == '.' && grid[x - 1][y] == '.' && grid[x - 1][y + 1] == 'H') {
                if (dist[x - 1][y + 1] == -1) {
                    dist[x - 1][y + 1] = dist[x][y] + 1;
                    q.push({ x - 1, y + 1 });
                }
            }
        }

        // 결과 출력
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'H') cout << (dist[i][j] == -1 ? -1 : dist[i][j]) << " ";
                else cout << "0 ";
            }
            cout << "\n";
        }
    }

    return 0;
}