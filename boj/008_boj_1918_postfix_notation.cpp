/***********************************************
 * 2025-07-30
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int det(char sign){
    int result;
    if(sign == '+' || sign == '-'){
        result = 0;
    }
    else if(sign == '*' || sign == '/' ){
        result = 1;
    }
    else{
        result = -1;
    }
    return result;
}

int main() {
    fastio;
    string infix;
    cin >> infix;

    stack<char> stack;

    for(int i = 0; i < infix.length(); ++i){
        if(infix[i] >= 'A' and infix[i] <= 'Z'){
            cout << infix[i];
        }
        else{
            if(stack.empty()){
                stack.push(infix[i]);
            }
            else{
                char now = infix[i];
                if(now == ')'){
                    while(stack.top() != '('){
                        cout << stack.top();
                        stack.pop();
                    }
                    stack.pop(); // '(' 지우기. 출력x
                }
                else if(now == '('){
                    stack.push(now);
                }
                else if(det(now) == 1 or det(now) == 0){
                    while(!stack.empty() && stack.top() != '(' && det(stack.top()) >= det(now)){
                        cout << stack.top();
                        stack.pop();
                    }
                    stack.push(now);                   
                }

            }

        }
    }
    while(!stack.empty()){
        cout << stack.top();
        stack.pop();
    }

    return 0;
}