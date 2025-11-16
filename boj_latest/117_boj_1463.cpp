/***********************************************
 * 2025-11-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int n;
int dp[1000001];

int solve(int x){
    dp[1] = 0;
    for(int i=2; i<=x; ++i){
        dp[i] = 1+dp[i-1];

        if(i%2 == 0){
            dp[i] = min(dp[i], 1+dp[i/2]);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i], 1+dp[i/3]);
        }
    }
    return dp[x];
}

int main() {
    fastio;
    cin >> n;
    cout << solve(n) << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}