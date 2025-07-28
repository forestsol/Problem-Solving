/***********************************************
 * 2025-06-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

static const int MOD = 10007;

int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc-- > 0){
        int n, m;
        cin >> n >> m;

        vector<int> dp(n+1, 0);
        for(int x = 1; x <= n ; ++x){
            vector<pair<int, int>> parts;
            if(x>m){
                int a = min(m, x-m);
                int b = max(m, x-m);
                parts.emplace_back(a, b);
            }
            if(x%2 == 0){
                int a = x/2, b= x/2;
                bool dup = false;
                for(auto &p:parts){
                    if(p.first == a && p.second == b){
                        dup = true;
                        break;
                    }
                }
                if(!dup) parts.emplace_back(a,b);
            }
            if(x>m && (x-m)%2==0){
                int a = (x-m)/2;
                int b = (x+m)/2;
                bool dup = false;
                for(auto &p:parts){
                    if(p.first == a && p.second == b){
                        dup = true;
                        break;
                    }
                }
                if(!dup) parts.emplace_back(a,b);
            }
            if(parts.empty()){
                dp[x] = 1;
            }else{
                int sum =0;
                for(auto &p : parts){
                    sum = (sum + dp[p.first] * dp[p.second]) % MOD;
                }
                dp[x] = sum;
            }
        }

        cout << dp[n] << endl;

    }

    return 0;
}