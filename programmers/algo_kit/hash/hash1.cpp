/***********************************************
 * 2026-04-23
 ***********************************************/
#include "../nlohmann/json.hpp"
using json = nlohmann::json;


#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

string solution(vector<string> participant, vector<string> completion){
    unordered_map<string, int> mp;
    for(string name : participant){
        mp[name]++;
    }
    for(string name : completion) {
        mp[name]--;
    }
    for(auto p : mp){
        if(p.second > 0){
            return p.first;
        }
    }
    
    return "";
}

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    string p = R"(["leo", "kiki", "eden"])";
    string c = R"(["eden", "kiki"])";

    auto participant = json::parse(p).get<vector<string>>();
    auto completion = json::parse(c).get<vector<string>>();
    cout << solution(participant, completion);
    return 0;
}