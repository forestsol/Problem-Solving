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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map;
    map.resize(n);
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        for(int j = 0; j < m; ++j){
            map[i].push_back(int(str[j] - '0'));
        }
    }
    int max_len = min(n, m);
    for(int cur_len = max_len; cur_len >= 2; --cur_len){
        for(int nsp = 0; nsp + cur_len - 1 < n; ++nsp){
            for(int msp = 0; msp + cur_len -1 < m; ++msp){
                if(map[nsp][msp] == map[nsp + cur_len - 1][msp] && map[nsp + cur_len - 1][msp] == map[nsp + cur_len - 1][msp + cur_len -1] && map[nsp + cur_len -1][msp + cur_len -1] == map[nsp][msp + cur_len -1]){
                    cout << cur_len * cur_len << endl;
                    return 0;
                }
            }
        }
    }
    cout << 1 << endl;
    return 0;
    
}