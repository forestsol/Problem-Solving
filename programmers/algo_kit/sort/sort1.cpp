/***********************************************
 * 2026-04-27
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(vector<int> cmd : commands){
        int i = cmd[0];
        int j = cmd[1];
        int k = cmd[2];

        vector<int> temp;
        for(int a=i-1; a<j; a++){
            temp.push_back(array[a]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
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
    string str1 = R"([1, 5, 2, 6, 3, 7, 4])";
    string str2 = R"([[2, 5, 3], [4, 4, 1], [1, 7, 3]])";
    auto input_data1 = json::parse(str1).get<vector<int>>(); // input_data, type setting
    auto input_data2 = json::parse(str2).get<vector<vector<int>>>();
    print_vector(solution(input_data1, input_data2));
    return 0;
}