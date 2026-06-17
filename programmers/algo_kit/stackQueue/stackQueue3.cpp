/***********************************************
 * 2026-04-26
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for(char c : s){
        if(!stk.empty()){
            if(c == '('){
                stk.push(c);
            }else{ // ')'
                if(stk.top() == '('){
                    stk.pop();
                }
            }
        }else{
            stk.push(c);
        }
    }
    if(!stk.empty()){
        answer = false;
    }
    return answer;
}

void print_vector(const vector<int>& v) {
    cout << "["; 
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ",";
    }
    cout << "]\n";
}
int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    string str = ")()(";
    cout << (solution(str) ? "true" : "false");

    return 0;
}