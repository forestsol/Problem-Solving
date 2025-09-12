/***********************************************
 * 2025-09-04
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    long long A, B;
    cin >> A >> B;
    cout << A*B / gcd(A, B) << endl;
    return 0;   
}