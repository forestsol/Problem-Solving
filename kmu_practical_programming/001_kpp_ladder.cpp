#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[3] = {0, 0, -1};
int dy[3] = {-1, 1, 0};

int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m, d; // 시작 번호의 갯수 n, 사다리의 크기 m, 목적지의 위치 d
        cin >> n >> m >> d;
        vector<string> ladder(m + 1); // 한줄씩 읽어서 해당 벡터에 저장
        for(int i = 0 ; i < m; i++){
            string s;
            getline(cin >> ws, s); 
            // getline : 공백을 포함한 문자열을 받기 위해 getline 사용,
            // ws : 전에 입력했던 숫자의 뒷부분에 달린 '\n'이 먼저 읽혀서 문자열 입력을 방해할 수 있음.
            ladder[i] = s;
        }
        int x = m-1;
        int y = d*2 - 2;

        while(x>0){
            bool moved = false;
            for(int i = 0; i < 3; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(ny > n*2-1) continue;
                if(ny <= 0) continue;

                char whatisnext = ladder[nx][ny];

                if(whatisnext == '+'){
                    x = x + dx[i];
                    y = y + dy[i]*2;
                    moved = true;
                    break;
                }
            }
            if(!moved == true) x--;
        }
        int result = (y+1)/2;
        cout << result << endl;
    }
    return 0;
}