/***********************************************
 * 2025-10-05
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
    int prev = 0;
    bool flag = true;
    stack<int> stk;
    for(int i=0; i<n; i++){
        int cur;
        cin >> cur;
        if(cur == prev+1){
            prev = cur;
            while(!stk.empty() && stk.top() == prev+1){
                prev = stk.top();
                stk.pop();
            }
        }else{
            if(stk.empty()){
                stk.push(cur);
            }else{
                if(stk.top() > cur){
                    stk.push(cur);
                }else{
                    flag = false;
                    break;
                }
            }
            
        }
    }
    if(flag){
        cout << "Nice" << endl;
    }else{
        cout << "Sad" << endl;
    }
    return 0;
}