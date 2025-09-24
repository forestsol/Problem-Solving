/***********************************************
 * 2025-09-14
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<bool> sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= n; ++i){
        if(is_prime[i]){
            for(int j = i*i; j <= n; j+=i){
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    fastio;
    int N;
    while((cin >> N) && N != 0){
        int cnt = 0;
        vector<bool> primes = sieve(2*N);
        for(int j=N+1; j<=2*N; j++){
            if(primes[j]){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}