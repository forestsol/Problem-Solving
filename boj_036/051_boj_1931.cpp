/***********************************************
 * 2025-08-27
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for(int i = 0; i < n ; i++){
        int strat_time;
        int end_time;
        cin >> strat_time >> end_time;
        times.emplace_back(strat_time, end_time);
    }
    sort(times.begin(), times.end(), compare);

    int cnt = 0;
    int end = 0;
    for(auto n : times){
        if(n.first >= end){
            end = n.second;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}