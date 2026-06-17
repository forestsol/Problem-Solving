/***********************************************
 * 2026-04-25
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prev = -1;
    
    for(auto i : arr){
        if(i != prev){
            answer.push_back(i);
        }
        prev = i;
    }

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
    string str = R"([1,1,3,3,0,1,1])";
    auto input_data = json::parse(str).get<vector<int>>(); // input_data, type setting
    auto result = solution(input_data); // input_data setting
    print_vector(result);
    return 0;
}