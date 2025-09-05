/***********************************************
 * 2025-08-30
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n, k;
    while(cin >> n >> k){
        int cnt = n;
        while(n/k != 0){
            cnt += n / k;
            n = n/k + n%k;
        }
    cout << cnt << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}