/***********************************************
 * 2025-10-15
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    long long x, y;
    cin >> x >> y;

    long long dist = y - x;
    if (dist == 0) {
        cout << 0;
        return 0;
    }

    long long n = sqrt(dist);

    if (dist == n * n)
        cout << 2 * n - 1;
    else if (dist <= n * n + n)
        cout << 2 * n;
    else
        cout << 2 * n + 1;
    // 알고리즘 문제 풀이 시작
    return 0;
}