/***********************************************
 * 2025-08-17
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    unordered_set<string> ss;
    int cnt = 0;
    for(int i = 0 ; i < n; i++){
        string s;
        cin >> s;
        ss.insert(s);
    }
    for(int j = 0; j < m; j++){
        string t;
        cin >> t;
        if(ss.count(t)){
            cnt++;
        }
    }
    cout << cnt << endl;
    


    // 알고리즘 문제 풀이 시작
    return 0;
}