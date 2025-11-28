/***********************************************
 * 2025-11-11
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int s[21];
int b[21];
int n, k;

int solve(int n, bool ljuse = false){
    int sj = INT_MAX, bj = INT_MAX, lj = INT_MAX;
    if(n == 1){
        return 0;
    }
    if(n-1 >= 1){
        sj = s[n-1] + solve(n-1, ljuse);
    }
    if(n-2 >= 1){
        bj = b[n-2] + solve(n-2, ljuse); 
    }
    if(n-3 >= 1 && !ljuse){
        ljuse = true;
        lj = k + solve(n-3, ljuse);
    }
    return min(min(sj, bj), lj);
}

int main() {
    fastio;
    cin >> n;
    for(int i=1; i<=n-1; i++){
        cin >> s[i] >> b[i];
    }
    cin >> k;

    int result = solve(n);

    cout << result << endl;
    
    // 알고리즘 문제 풀이 시작
    return 0;
}