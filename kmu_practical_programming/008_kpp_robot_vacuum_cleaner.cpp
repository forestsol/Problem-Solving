#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1}; // 북 : 0 동 : 1 남 : 2 서 :3


int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int n, d;
        cin >> n >> d; // 격자크기 n, 로봇 방향 d (북, 동, 남, 서)

        vector<vector<int>> room(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n));

        int r, c; // 로봇의 시작 위치
        cin >> r >> c;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> room[i][j];
            }
        }

        int result = 0;
        while(true){
            if(!visited[r][c]){
                visited[r][c] = true;
                result++;
            }
            bool found = false; // 다음 탐색을 진행할 필요가 있음을 나타내는 플래그
            for(int i =0; i < 4; i++){
                d = (d+3) % 4 ; // 중요-- 회전

                int nr = r+dr[d];
                int nc = c+dc[d];

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && room[nr][nc] == 0 && !visited[nr][nc]){
                    r = nr;
                    c = nc;
                    found = true;
                    break; // 4방향 탐색중 끊고 나오기.
                }
            }
            if(found){ // 방향 이동 후 청소 진행
                continue;
            }

            int back_d = (d+2) % 4; // 현재 방향과 정 반대 방향으로 설정
            int br = r + dr[back_d];
            int bc = c + dc[back_d];

            if(br>=0 && bc >= 0 && br < n && bc < n && room[br][bc] == 0){
                r = br;
                c = bc;
            }
            else{
                break;
            }
        }

        cout << result << endl;
    }
    
    return 0;
}