/***********************************************
 * 2026-04-26
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int prev = -1;
    int count = 0;
    for(int i=0; i<progresses.size(); i++){
        int need = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0){
            need += 1;
        }

        if(prev < need){
            if(count != 0){
                answer.push_back(count);
            }
            count = 1;
            prev = need;
            
        }else{
            count++;
        }
    }
    answer.push_back(count);
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
    string str1 = R"([95, 90, 99, 99, 80, 99])";
    string str2 = R"([1, 1, 1, 1, 1, 1])";
    auto input_data1 = json::parse(str1).get<vector<int>>();
    auto input_data2 = json::parse(str2).get<vector<int>>();
    print_vector(solution(input_data1, input_data2));

    return 0;
}