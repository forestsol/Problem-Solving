/***********************************************
 * 2025-08-23
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    map<int, int> num_card;
    for(int i = 0; i < n ; i++){
        int num;
        cin >> num;
        num_card[num]++;
    }
    int m;
    cin >> m;
    for(int j = 0; j < m ; j++){
        long long ans;
        cin >> ans;
        cout << num_card[ans] << ' ';        
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}