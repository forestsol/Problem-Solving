/***********************************************
 * 2026-04-24
 ***********************************************/

#include "../nlohmann/json.hpp"
#include <bits/stdc++.h>

using json = nlohmann::json;
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int solution(vector<int> nums)
{
    int answer = 0;

    unordered_map<int, int> mp;
    for(int ptype : nums){
        mp[ptype]++;
    }

    if(mp.size() >= nums.size()/2){
        answer = nums.size()/2;
    }
    else{
        answer = mp.size();
    }

    return answer;
}

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작`
    string n = R"([3,3,3,2,2,4])";

    auto nums = json::parse(n).get<vector<int>>();
    cout << solution(nums);

    return 0;
}