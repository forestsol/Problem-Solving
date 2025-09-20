/***********************************************
 * 2025-09-16
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

long long max_val = INT_MIN;
vector<int> nums;
vector<char> ops;

long long calculate(long long num1, long long num2, char op){
    if(op == '+'){
        return num1 + num2;
    }else if(op == '-'){
        return num1 - num2;
    }else if(op =='*'){
        return num1 * num2;
    }
    return 0;
}

void solve(int op_idx, long long val){
    if(op_idx >= ops.size()){
        max_val = max(max_val, val);
        return;
    }

    long long res1 = calculate(val, nums[op_idx + 1], ops[op_idx]);
    solve(op_idx+1, res1);

    if(op_idx + 1 < ops.size()){
        long long res2 = calculate(nums[op_idx + 1], nums[op_idx + 2], ops[op_idx + 1]);
        solve(op_idx + 2, calculate(val, res2, ops[op_idx]));
    }
}

int main() {
    fastio;
    int n;
    int max = 0;
    string str;

    cin >> n; // 1 <= n <= 19
    cin >> str;

    for(int i=0; i<n; ++i){
        if(i%2 == 0){
            nums.push_back(int(str[i] -'0'));
        }else{
            ops.push_back(str[i]);
        }
    }
    
    solve(0, nums[0]);

    cout << max_val << endl;

    // 알고리즘 문제 풀이 시작
    return 0;
}