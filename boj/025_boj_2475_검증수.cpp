/***********************************************
 * 2025-08-12
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int verification = (a*a + b*b + c*c + d*d + e*e) % 10;
    cout << verification << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}