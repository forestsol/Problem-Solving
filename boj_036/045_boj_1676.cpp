/***********************************************
 * 2025-08-22
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    int ans = 0;
    for(long long p = 5; p <= n; p*=5){
        ans = ans + n/p;
    }
    cout << ans << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}