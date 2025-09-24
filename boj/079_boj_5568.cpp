/***********************************************
 * 2025-09-19
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

set<string> results;
vector<int> nums;
int n, k;

void permuteUnique(vector<int>& nums, int depth){
    if(depth == k){
        string s;
        for(int i = 0; i < k; i++){
            s += to_string(nums[i]);
        }
        results.insert(s);
        return;
    }
    for(int i = depth; i<nums.size(); ++i){
        if(i != depth && nums[i] == nums[depth]) continue;
        swap(nums[depth], nums[i]);
        permuteUnique(nums, depth + 1);
        swap(nums[depth], nums[i]);
    }
}

int main() {
    fastio;
    cin >> n >> k;
    while(n-- >0){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    permuteUnique(nums, 0);
    cout << results.size() << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}