/***********************************************
 * 2025-10-15
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    vector<int> nums;
    int n, m; cin >> n >> m;
    for(int i =0; i<n; ++i){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int cnt =0;
    if(n != 1){
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                if(nums[i]+nums[j] == m){
                    cnt++;
                }
            }
        }
    }
    
    cout << cnt << endl;
    
    

    return 0;
}