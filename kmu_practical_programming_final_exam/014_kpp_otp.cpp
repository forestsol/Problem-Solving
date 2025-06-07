/***********************************************
 * 2025-05-09
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

static const int MOD = 999983;

inline int gen_otp(long long A, long long B, long long C, long long t) {
    long long tm = t % MOD;
    long long t2 = (tm * tm) % MOD;
    long long res = (A % MOD) * t2 % MOD;
    res = (res + (B % MOD) * tm) % MOD;
    res = (res + (C % MOD)) % MOD;
    return int(res);
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--> 0){
        int n;
        cin >> n;
        vector<long long> A(n+1), B(n+1), C(n+1);        
        for(int i = 1; i <= n; ++i){
            cin >> A[i] >> B[i] >> C[i];
        }

        int m;
        cin >> m;

        while(m--> 0){
            int u;  // 고객번호 u
            long long t, x;  // OTP 입력시간 t, 입력된 OTP x
            cin >> u >> t >> x;

            bool ok = false;

            for(long long dt = -3; dt <= 3; ++dt){  // -3분부터 +3분까지 7개의 경우의 수 검사
                long long tt = t + dt;  // 오차 적용 시간 tt
                if(tt < 1) continue;  // 시간이 음수일 경우 검사할 필요 없음.
                if(gen_otp(A[u], B[u], C[u], tt) == x){   // 고유 계수와, 현재 시간을 바탕으로 계산한 이 otp가 유효한지 검사
                    ok = true;
                    break;
                }
            }

            cout << (ok ? "YES\n" : "NO\n");
        }

    }

    return 0;
}   