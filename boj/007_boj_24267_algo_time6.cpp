/***********************************************
 * 2025-07-29
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    int degree = 3;
    long long int cnt = 0;

    for(int i = 0 ; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    cout << degree << endl;

    return 0;
}