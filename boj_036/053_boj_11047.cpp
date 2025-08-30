/***********************************************
 * 2025-08-28
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
    vector<int> coins;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    for(int j = coins.size()-1; j >= 0 ; j--){
        cnt = cnt + k/coins[j];
        k = k % coins[j];
    }
    cout << cnt << endl;
    return 0;
}