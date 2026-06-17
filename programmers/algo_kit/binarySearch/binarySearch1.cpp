/***********************************************
 * 2026-04-28
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

long long solution(int n, vector<int> times) {
    long long answer = 0;
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
    int n = 6;
    string str = R"([7, 10])";
    auto input_data = json::parse(str).get<vector<int>>(); // input_data, type setting
    cout << solution(n, input_data); // input_data setting

    return 0;
}