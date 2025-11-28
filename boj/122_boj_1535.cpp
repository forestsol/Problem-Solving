/***********************************************
 * 2025-11-19
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int peopleMax = 20;
int n;
int L[peopleMax]; // 체력 사용량
int J[peopleMax]; // 기쁨 사용량
int dp[100]; // 체력x를 사용할 때, 얻을 수 있는 기쁨의 최댓값

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> L[i];
    }
    for(int j=0; j<n; j++){
        cin >> J[j];
    }
    for(int k=0; k<=100; k++){
        dp[k] = 0;
    }
}

void solve(){
    for(int i=0; i<n; i++){
        for(int k=100; k>=L[i]; k--){
            dp[k] = max(dp[k-L[i]] + J[i], dp[k]);
        }
    }
    int ans;
    for(int h=0; h<=99; h++){
        ans = max(ans, dp[h]);
    }
    cout << ans << endl;
}

void solution(){
    input();
    solve();
}

int main() {
    fastio;
    solution();
    // 알고리즘 문제 풀이 시작
    return 0;
}