/***********************************************
 * 2025-10-09
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
    queue<int> q;
    for(int i=1; i<=n; ++i){
        q.push(i);
    }
    cout << '<';
    while(!q.empty()){
        for(int i=0; i<k-1; ++i){
            q.push(q.front()); q.pop();
        }
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << '>';
    return 0;
}