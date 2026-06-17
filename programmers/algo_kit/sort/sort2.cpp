/***********************************************
 * 2026-04-27
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> v;
    for(int n : numbers){
        v.push_back(to_string(n));
    }
    sort(v.begin(), v.end(), cmp);

    string answer = "";
    for(auto &s : v){
        answer += s;
    }

    if(answer[0] == '0') return "0";

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
    string str = R"([6, 10, 2])";
    auto input_data = json::parse(str).get<vector<int>>(); // input_data, type setting
    cout << solution(input_data); // input_data setting

    return 0;
}