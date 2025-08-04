/***********************************************
 * 2025-08-03
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int N;
    cin >> N;
    int flag = 0;
    for(int i = 1; i < N; ++i){
        int now = i;
        int dec_sum = i;
        while(now){
            dec_sum += now % 10;
            now /= 10;
        }
        if(dec_sum == N){
            cout << i << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << 0 << endl;
    }

    return 0;
}