/***********************************************
 * 2025-06-12
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc-- > 0){
        int n;
        cin >> n;

        vector<pair<long long, int>> events;
        vector<int> position(n);
        vector<int> range(n);

        for(int i = 0; i < n; i++){
            cin >> position[i];
        }
        for(int i = 0; i < n; i++){
            cin >> range[i];
        }
        for(int i = 0; i < n; i++){
            int left = position[i] - range[i];
            int right = position[i] + range[i];
            events.push_back({left, 1});
            events.push_back({right + 1, -1});
        }
        sort(events.begin(), events.end());

        int max_water = 0;
        int current_water =0;
        long long answer_pos = 0;

        for(auto event : events){
            current_water += event.second;

            if(current_water > max_water){
                max_water = current_water;
                answer_pos = event.first;
            }
        }
        cout << answer_pos << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}