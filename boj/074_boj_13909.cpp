/***********************************************
 * 2025-09-14
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int n;
    cin >> n;
    int cnt = 1;
    for(int i = 2; i*i <= n; ++i){
        cnt++;
    }
    cout << cnt << endl;

    

    return 0;
}