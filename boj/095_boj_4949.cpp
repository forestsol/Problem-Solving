/***********************************************
 * 2025-10-04
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    while(true){
        bool flag = true;
        stack<char> stk;
        string s;
        getline(cin, s);
        if(s.length() == 1 && s[0] == '.'){
            break;
        }

        for(char c : s){
            if(c == '(' || c == '['){
                stk.push(c);
            }
            if(c == ')'){
                if(!stk.empty()){
                    if(stk.top() == '(' && !stk.empty()){
                        stk.pop();
                    }
                    else{
                        flag = false;
                        break;
                    }
                }else{
                    flag = false;
                    break;
                }
            }
            if(c == ']'){
                if(!stk.empty()){
                    if(stk.top() == '[' && !stk.empty()){
                        stk.pop();
                    }
                    else{
                        flag = false;
                        break;
                    }
                }else{
                    flag = false;
                    break;
                }            
            }
            if(c == '.'){
                if(!stk.empty()) flag = false; break;
            }
        }
        if(flag){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }        
    }
    return 0;
}