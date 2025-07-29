/***********************************************
 * 2025-07-29
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    string sticks;
    cin >> sticks;
    stack<char> stack;
    int result = 0;
    char prev = '0';

    for(int i = 0; i < sticks.length(); i++){
        if(sticks[i] == '('){
            stack.push(sticks[i]);
        }
        else{
            if(prev == '('){
                stack.pop();
                result += stack.size();
            }
            else if(prev == ')'){
                stack.pop();
                result += 1;
            }
        }
        prev = sticks[i];
    }
    
    cout << result << endl;
    return 0;
}