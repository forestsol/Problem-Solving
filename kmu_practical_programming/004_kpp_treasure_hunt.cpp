/***********************************************
 * 2025-04-14
 * 004_실전프로젝트-보물찾기-std
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

// 방향 숫자 의미
// 0: 아래쪽 (F)
// 1: 왼쪽  (L)
// 2: 위쪽  (B) ← 처음 시작
// 3: 오른쪽 (R)

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        bool visited[52][52][4] = {false}; // 방문했던 곳인지 기록
        char posit[52][52][4]; // 위치와 이동방향 기록

        cin >> n;
        for(int i = 0; i < n ; i++){
            for(int j =0; j < n ; j++){
                cin >> posit[i][j]; // posit[i][j][0]에 방향 기록 ( ex : 'R' ) + posit[i][j][1]에 거리 기록 ( ex : '2' )
                // 입력값 "R2"는 문자열 리터럴 "R2\0"로 들어가고,
                // C++에서는 문자열 입력을 받을 때 \0(널 문자)까지 포함해서 자동으로 분리돼요.
                // 입력: R2
                // arr[0] = 'R'
                // arr[1] = '2'
                // arr[2] = '\0'
                // arr[3] = ? (안 씀)
            }                
        }

        int y = 0, x =0; // 시작 위치 0,0
        int prev = 2; // 시작 전 이동방향은 B로 함.

        while(true){
            if(visited[y][x][prev] == true) break;// y, x 로 위치도 같고, prev가 동일하면(이전 이동방향이 같으면, 
                                                  // 여기 위치에 적힌 단어는 동일하니까 다음 이동방향이 같게됨.) 보물을 찾은 것.
            else visited[y][x][prev] = true;
            
            char curr = posit[y][x][0]; // 이번 칸이 제시하는 방향
            
            if(curr == 'B') prev = (prev + 2) % 4;
            else if(curr == 'F') prev = (prev + 0) % 4;
            else if(curr == 'R') prev = (prev + 3) % 4;
            else if(curr == 'L') prev = (prev + 1) % 4; // 이동방향 계산 (이전 방향 값 + 다음 방향 값) % 4

            int move = posit[y][x][1] - '0'; // 움직일 값 계산. posit[y][x][1]에 들어있는 char을 꺼내고 - char '0'을 빼서 ASCII계산을 함.

            if(prev == 0) y += move; // 0이면 아래쪽(F)으로 이동
            else if(prev == 1) x -= move; // 1이면 왼쪽(L)으로 이동
            else if(prev == 2) y -= move; // 2이면 위쪽(B)으로 이동
            else if(prev == 3) x += move; // 3이면 오른쪽(R)으로 이동
        }
        cout << y << ' ' << x << endl;
    }
    return 0;
}