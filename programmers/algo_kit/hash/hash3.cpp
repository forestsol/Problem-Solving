/***********************************************
 * 2026-04-24
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool solution(vector<string> phone_book) {
    unordered_map<string, int> mp;
    unordered_map<string, int> edit;
    bool answer = true;

    for(string phone : phone_book){
        if(phone.length()>=2){
            for(int i=1; i<phone.length(); i++){
                mp[phone.substr(0, i)]++;
            }
        }
        mp[phone]++;        
    }
    for(string phone : phone_book){
        if(mp[phone] != 1){
            answer = false;
            return answer;
        }
    }
    return answer;
}

int main() {
    fastio;
    string p = R"(["119", "97674223", "1195524421"])";

    auto phone_book = json::parse(p).get<vector<string>>();
    bool result = solution(phone_book);
    cout << result;
    // 알고리즘 문제 풀이 시작

    return 0;
}