/***********************************************
 * 2026-04-27
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    for(int i=0; i<bridge_length; i++){
        bridge.push(0);
    }

    int time = 0;
    int sum = 0;
    int idx = 0;

    while(idx < truck_weights.size()){
        time++;

        sum -= bridge.front();
        bridge.pop();

        if(sum + truck_weights[idx] <= weight){
            bridge.push(truck_weights[idx]);
            sum += truck_weights[idx];
            idx++;
        }else{
            bridge.push(0);
        }
    }
    return time + bridge_length;
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
    string str = R"([10,10,10,10,10,10,10,10,10,10])";
    int bridge_length = 100;
    int weight = 100;
    auto input_data = json::parse(str).get<vector<int>>(); 
    cout << solution(bridge_length, weight, input_data); 
    return 0;
}