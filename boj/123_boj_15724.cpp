/***********************************************
 * 2025-11-20
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int mapMax = 1025;
const int kMax = 100000;
int n, m, k;
int land[mapMax][mapMax];
int dp[mapMax][mapMax];
int coord[kMax][4];

void input(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> land[i][j];
        }
    }
    cin >> k;
    for(int i=0; i<k; i++){
        for(int j=0; j<4; j++){
            cin >> coord[i][j];
        }
    }
}

void solve(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + land[i][j];
        }
    }
    
    for(int i=0; i<k; i++){
        int result;
        int xs = coord[i][0]; 
        int ys = coord[i][1]; 
        int xe = coord[i][2]; 
        int ye = coord[i][3];
        result = dp[xe][ye] - dp[xs-1][ye] - dp[xe][ys-1] + dp[xs-1][ys-1];
        cout << result << endl;
    }
}

void solution(){
    input();
    solve();
}

int main() {
    fastio;
    solution();
    // 알고리즘 문제 풀이 시작
    return 0;
}