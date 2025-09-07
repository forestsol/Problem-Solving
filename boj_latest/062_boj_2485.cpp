/***********************************************
 * 2025-09-06
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
    vector<int> nums(n);
    for(int i = 0 ; i < n; i++){
        cin >> nums[i];
    }
    int gcd_num = 0;
    for(int i = 1; i < n; i++){
        int sub = nums[i] - nums[i-1];
        gcd_num = gcd(sub, gcd_num);
    }

    int tree_count = ((nums.back() - nums.front()) / gcd_num) - (n-1);
    cout << tree_count << endl;

    return 0;
}