/***********************************************
 * 2025-10-07
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n ; ++i){
        q.push(i);
    }
    while(q.size() != 1){
        q.pop();
        int cur_front = q.front(); q.pop();
        q.push(cur_front);
    }
    cout << q.front() << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}