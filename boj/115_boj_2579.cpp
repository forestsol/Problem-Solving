/***********************************************
 * 2025-11-12
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int n;
int score[301];
int dp[301];

int solve(int n){
    dp[1] = score[1];
    dp[2] = score[2]+score[1];
    
    for(int i = 3; i <= n; ++i){
        dp[i] = max(dp[i-2]+score[i], dp[i-3]+score[i-1]+score[i]);
    }
    return dp[n];
}

int main() {
    fastio;
    score[0] = 0;
    dp[0] = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> score[i];
    }

    int result = solve(n);

    cout << result << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}