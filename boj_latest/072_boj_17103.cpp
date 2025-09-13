/***********************************************
 * 2025-09-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<bool> sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i < n; ++i){
        if(is_prime[i]){
            for(int j = i*i ; j <= n ; j += i){
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    fastio;
    int t;
    cin >> t;
    
    for(int i = 0; i < t; ++i){
        int n;
        int cnt = 0;
        cin >> n;
        vector<bool> primes = sieve(n);
        for(int j = 2; j <= n/2; ++j){
            bool temp1 = primes[j];
            bool temp2 = primes[n-j];
            if(primes[j] && primes[n-j]){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}