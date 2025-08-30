/***********************************************
 * 2025-08-19
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    fastio;
    int n;
    cin >> n;

    int x = n;

    while(true){
        string s = to_string(x);
        string t = s;
        reverse(s.begin(), s.end());
        if(s == t && isPrime(x)){
            cout << x << endl;
            break;
        }
        ++x;
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}