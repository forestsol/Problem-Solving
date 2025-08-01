/***********************************************
 * 2025-08-01
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int MAX = 66610000;

int main() {
    fastio;
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 666; i <= MAX; i++){
        string title = to_string(i);
        auto pos = title.find("666");
        if(pos != string::npos){
            cnt++;
            if(cnt == n){
                cout << i;
                break;
            }
        }
        else{
            continue;
        }
    }
    return 0;
}