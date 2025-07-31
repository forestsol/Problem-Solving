/***********************************************
 * 2025-07-31
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    string postfix;
    cin >> postfix;
    vector<int> values;
    for(int i = 0; i < n ; ++i){
        int value;
        cin >> value;
        values.push_back(value);
    }

    stack<double> stk;

    for(int j = 0; j < postfix.length(); ++j){
        if(postfix[j] >= 'A' && postfix[j] <= 'Z'){
            int idx = postfix[j] - 'A';
            stk.push(values[idx]);
        }
        else{
            double second = stk.top();
            stk.pop();
            double first = stk.top();
            stk.pop();
            double result = 0;

            if(postfix[j] == '+'){
                result = first + second;
            }
            else if(postfix[j] == '-'){
                result = first - second;
            }
            else if(postfix[j] == '*'){
                result = first * second;
            }
            else if(postfix[j] == '/'){
                result = first / second;
            }

            stk.push(result);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << stk.top() << endl;

    return 0;
}