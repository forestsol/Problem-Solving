#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int node, vector<vector<int>>& map, vector<vector<bool>>& visited){

}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m;
        cin >> n >> m; // 격자크기 n, 사람 수 m

        vector<vector<int>> map(n, vector<int>(n)); // 격자 배열
        for(int a = 0; a < n; a++){ // 격자 입력받기
            for(int b = 0; b < n; b++){
                cin >> map[a][b];
            }
        }

        vector<pair<int, int>> pos(m); // 사람별 목표 위치 
        for(int j = 0; j < m; j++){
            int r, c; // 행 r, 열 c
            cin >> r >> c;
            pos[j].first = r - 1; // index를 위해 수정
            pos[j].second = c - 1; // index를 위해 수정
        }


        // 목표지점과 가장 가까운 숙소 위치를 정해야 함.
        // 두개가 정해졌다면, 최단거리 탐색을 해야함.
        // 최단거리 탐색 중 장애물을 만났다면 돌아가야 함.
        // 일단 최단거리를 찾아 움직이고, 도착했을 때 자신이 몇번째 순서이냐에 따라 해당하는 순서만큼 시간에 더하면 됨.

        // 목표지점에 도착한 사람 중 가장 큰 숫자를 가진 사람이 정답.

    }
    return 0;
}