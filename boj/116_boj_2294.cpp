/***********************************************
 * 2025-11-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, k;
int values[101];
int dp[100001]; // dp[A] = B  : A원일 때, 최소로 쓰는 동전 갯수인 B를 기록하는 dp

int solve(int k){
    for(int i=1; i<=k; ++i){
        dp[i] = 2e9;  // dp는 일단 무지막지하게 많은 동전의 갯수를 쓰는 것으로 생각
    }
    for(int i=0; i<n; ++i){
        dp[values[i]] = 1;  // A원에서 같은 가치를 가진 동전은 딱 1번만 쓰면 그 가격이 됨. 미리 dp 채워두기.
    }
    dp[0] = 0; // 0원은 0개 씀. dp[1] = 1 + dp[1-1] 일때 예외를 막아줌.
    for(int i=0; i<n; ++i){  // n개의 동전을 돌리는 반복문
        for(int j=values[i]; j<=k; ++j){  // 1부터(사실은 n번째 동전의 가치부터 시작) k까지 dp를 돌리는 반복문
            dp[j] = min(dp[j], 1+dp[j-values[i]]);  // 점화식.
        }
    }
    if(dp[k] == 2e9){
        return -1;
    }else{
        return dp[k];
    }

}

int main() {
    fastio;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> values[i];
    }

    int result = solve(k);

    cout << result << endl;

    // 알고리즘 문제 풀이 시작
    return 0;
}