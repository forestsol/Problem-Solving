/***********************************************
 * 2026-04-24
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> mp;
    for(auto c : clothes){
        string type = c[1];
        mp[type]++;
    }
    int answer = 1;

    for(auto p : mp){
        answer *= (p.second + 1);
    }

    return answer - 1;
}

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    string str = R"([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]])";
    auto input_data = json::parse(str).get<vector<vector<string>>>(); // input_data, type setting
    cout << solution(input_data); // input_data setting

    return 0;
}