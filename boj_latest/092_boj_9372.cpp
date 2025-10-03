/***********************************************
 * 2025-10-02
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int national_max = 1001;

vector<int> world[national_max];

int main() {
    fastio;
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0; i<m; ++i){
            int a, b;
            cin >> a >> b;
            world[a].push_back(b);
            world[b].push_back(a);
        }
        // cout << n-1 << endl;
        

    }
    // 알고리즘 문제 풀이 시작
    return 0;
}