/***********************************************
 * 2025-09-12
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<bool> sieve(int m, int n){  // 에라토스테네스의 채.
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= n; ++i){
        if(is_prime[i]){
            for(int j = i*i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    fastio;
    int start, end;
    cin >> start >> end;
    auto primes = sieve(start, end);
    for(int i = start; i <= end; i++ ){
        if(primes[i]){
            cout << i << endl;
        }
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}