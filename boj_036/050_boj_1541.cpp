/***********************************************
 * 2025-08-25
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    string expr;
    cin >> expr;
    vector<string> div_expr;
    int sum = 0;
    int sub = 0;

    if(expr.find("-") != string::npos){
        size_t pos = expr.find("-");
        string sums = expr.substr(0, pos);
        string subs = expr.substr(pos+1);
        while(sums.find("+") != string::npos){
            size_t pos_sum = sums.find("+");
            sum += stoi(sums.substr(0, pos_sum));
            sums = sums.substr(pos_sum+1);
        }
        sum += stoi(sums);
        while(subs.find("+") != string::npos || subs.find("-") != string::npos){
            size_t pos_sub_plus = subs.find("+");
            size_t pos_sub_minus = subs.find("-");
            size_t pos_sub = min(pos_sub_plus, pos_sub_minus);
            sub += stoi(subs.substr(0, pos_sub));
            subs = subs.substr(pos_sub+1);
        }
        sub += stoi(subs);
    }else{
        while(expr.find("+") != string::npos){
            size_t pos_expr = expr.find("+");
            sum += stoi(expr.substr(0, pos_expr));
            expr = expr.substr(pos_expr+1);
        }
        sum += stoi(expr);
    }

    cout << sum - sub << endl;

    return 0;
}