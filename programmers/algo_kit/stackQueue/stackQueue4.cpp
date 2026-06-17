/***********************************************
 * 2026-04-26
 ***********************************************/

#include "../nlohmann/json.hpp"
using json = nlohmann::json;
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int solution(vector<int> priorities, int location) {
    
    queue<int> q;
    queue<int> name;
    priority_queue<int> pq;
    int answer = 0;

    for(int i = 0; i < priorities.size(); i++){
        q.push(priorities[i]);
        pq.push(priorities[i]);
        name.push(i);
    }
    while(!q.empty()){
        if(q.front() < pq.top()){
            int num = q.front();
            int idx = name.front();
            q.pop();
            name.pop();
            q.push(num);
            name.push(idx);
        }else{
            answer++;
            q.pop();
            pq.pop();
            int idx = name.front();
            name.pop();
            if(idx == location){
                return answer;
            }
        }
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
    string str = R"([1, 1, 9, 1, 1, 1])";
    int location = 0;
    auto input_data = json::parse(str).get<vector<int>>(); // input_data, type setting
    cout << solution(input_data, location); // input_data setting

    return 0;
}