/***********************************************
 * 2025-08-04
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int n;
    cin >> n;
    int result = -1;
    int minvalue = INT_MAX;
    for(int i = 0; i <= n/5; ++i){
        int m = n-5*i;
        if(m%3 == 0){
            minvalue = min(minvalue, i+m/3);
            result = minvalue;
        }
    }
    cout << result << endl;
    return 0;
}