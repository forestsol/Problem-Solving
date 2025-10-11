/***********************************************
 * 2025-10-12
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long sum = 0;
        vector<long long> nums;
        for(int i=0; i<n; ++i){
            long long num; cin >> num;
            nums.push_back(num);
        }
        for(int j=0; j<n-1; ++j){
            for(int k=j+1; k<n; ++k){
                sum += gcd(nums[j], nums[k]);
            }
        }
        cout << sum << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}