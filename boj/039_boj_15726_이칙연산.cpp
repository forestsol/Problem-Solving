/***********************************************
 * 2025-08-16
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int a, b, c;
    cin >> a >> b >> c;

    int d = a * b / c;
    int e = a / b * c;

    cout << 1/10 << endl;

    if(d >= e){
        cout << d;
    } else cout << e;

    // 알고리즘 문제 풀이 시작
    return 0;
}