/***********************************************
 * 2025-09-03
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int n, k;
    cin >> n >> k;
    vector<int> coins;
    vector<int> dp;
    coins.resize(n);
    dp.resize(k+1);
    for(int i = 0; i < n ; i++){
        cin >> coins[i];
    }

    dp[0] = 1;
    for(int c : coins){
        for(int j = c; j <= k; j++){
            dp[j] += dp[j - c];
        }
    }
    cout << dp[k] << endl;
    return 0;
}