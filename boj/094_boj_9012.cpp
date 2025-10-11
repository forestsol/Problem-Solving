/***********************************************
 * 2025-10-03
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<char> stk;
        for(char c : s){
            if(c == '('){
                stk.push('(');
            }
            else{
                if(!stk.empty()){
                    stk.pop();
                }
                else{
                    stk.push(')');
                    break;
                }
            }
        }
        if(stk.empty()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}