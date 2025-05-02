/***********************************************
 * 2025-05-02
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[] = {0, 0, -1};
int dy[] = {-1, 1, 0};

int main() {
    fastio;
    int t;
    cin >> t;

    while(t-- > 0){
        int n, m, d;
        cin >> n >> m >> d;
        vector<string> ladder(m+1);

        for(int i = 0; i < m ; i++){
            string s;
            getline(cin >> ws, s);
            ladder[i] = s;
        }

        int x = m - 1;
        int y = d*2 -2;

        while(x > 0 ){
            for(int i = 0; i<3; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(ny > n*2-2) continue;
                if(ny < 0) continue;

                if(ladder[nx][ny] == '+'){
                    x = x-1;
                    y = y + dy[i]*2;
                    break;
                }
            }
        }
        int result = (y + 2) / 2;
        cout << result << endl;
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}