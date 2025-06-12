/***********************************************
 * 2025-06-12
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

static const int MOD = 999983;

inline int gen_otp(long long A, long long B, long long C, long long t){
    long long tm = t%MOD;
    long long t2 = (tm * tm)%MOD;
    long long res = ((A%MOD) * t2)%MOD;
    res = (res + (B%MOD)*tm)%MOD;
    res = (res + (C%MOD))%MOD;
    return int(res);
}

int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--> 0){
        int n; // 고객수
        cin >> n;
        vector<long long> A(n+1), B(n+1), C(n+1);
        for(int i = 1; i <= n; ++i){
            cin >> A[i] >> B[i] >> C[i];
        }

        int m;
        cin >> m;

        while(m --> 0){
            int u;
            long long t, x;
            cin >> u >> t >> x;

            bool ok = false;

            for(long long dt = -3; dt <= 3; ++dt){
                long long tt = t + dt;
                if(tt < 1) continue;
                if(gen_otp(A[u], B[u], C[u], tt) == x){
                    ok = true;
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}