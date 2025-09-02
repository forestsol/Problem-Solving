/***********************************************
 * 2025-09-01
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<bool> winner;

int main() {
    fastio;
    int n;
    cin >> n;
    winner.resize(n+1);
    winner[1] = true;
    winner[2] = false;
    winner[3] = true;

    for(int i = 4; i <= n; i++){
        winner[i] = !winner[i-3];
    }
    if(winner[n]){
        cout << "SK" << endl;
    }else{
        cout << "CY" << endl;
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}