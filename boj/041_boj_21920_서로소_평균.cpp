/***********************************************
 * 2025-08-18
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i =0 ; i < n ; i++){
        cin >> a[i];
    }

    long long x;
    cin >> x;

    long long sum = 0;
    long long cnt = 0;
    for(int i = 0; i < n ; i++){
        if(gcd(a[i], x) == 1){
            sum += a[i];
            cnt++;
        }
    }
    cout << (long double)sum/cnt << endl;

    // 알고리즘 문제 풀이 시작
    return 0;
}