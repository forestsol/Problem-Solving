/***********************************************
 * 2025-08-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    string s;
    cin >> s;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] >= 65 && s[i] <= 90){
            cout << char(s[i] + 32);
        }
        else if(s[i] >= 97 && s[i] <= 122){
            cout << char(s[i] - 32);
        }
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}