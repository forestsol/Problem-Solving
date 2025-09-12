/***********************************************
 * 2025-09-11
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool is_prime(long long x){
    if(x == 0 || x == 1){
        return false;
    }
    if (x == 2 || x == 3) 
        return true;

    if (x % 2 == 0 || x % 3 == 0)
        return false;

    for(long long i = 5; i*i <= x; i++){
        if(x % i == 0){
            return false;
        }
    }

    return true;
}

int main() {
    fastio;
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        long long n;
        cin >> n;
        while(!is_prime(n)){
            n++;
        }
        cout << n << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}