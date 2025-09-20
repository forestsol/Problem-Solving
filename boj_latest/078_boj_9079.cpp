/***********************************************
 * 2025-09-17
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int t;
    cin >> t;

    vector<int> ops;

    ops.push_back(0b111000000);
    ops.push_back(0b000111000);
    ops.push_back(0b000000111);

    ops.push_back(0b100100100);
    ops.push_back(0b010010010);
    ops.push_back(0b001001001);
    
    ops.push_back(0b100010001);
    ops.push_back(0b001010100);

    while(t-- >0){
        int start = 0;
        for(int i=0; i<9; ++i){
            char c;
            cin >> c;

            if(c == 'T') {
                start |= ( 1 << (8-i));
            }
        }

        queue<pair<int, int>> q;
        vector<int> dist(521, -1);

        q.push({start, 0});
        dist[start] = 0;

        int answer = -1;

        while(!q.empty()){
            auto[cur, d] = q.front(); q.pop();

            if(cur == 0 || cur == 511){
                answer = d;
                break;
            }

            for(int mask : ops){
                int nxt = cur^mask;
                if(dist[nxt] == -1){
                    dist[nxt] = d+1;
                    q.push({nxt, d+1});
                }
            }
        }
        cout << answer << endl;
    }


    // 알고리즘 문제 풀이 시작
    return 0;
}