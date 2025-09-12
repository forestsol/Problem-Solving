/***********************************************
 * 2025-09-10
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n, K;
    cin >> n >> K;

    vector<int> W(n), V(n);
    for (int i = 0; i < n; ++i) cin >> W[i] >> V[i];

    vector<int> dp(K + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int cap = K; cap >= W[i]; --cap) {
            dp[cap] = max(dp[cap], dp[cap - W[i]] + V[i]);
        }
    }

    cout << dp[K] << '\n';
}