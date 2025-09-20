#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;

    // 연산 마스크 (9비트)
    vector<int> ops;

    // 행
    ops.push_back(0b111000000); // 1행
    ops.push_back(0b000111000); // 2행
    ops.push_back(0b000000111); // 3행

    // 열
    ops.push_back(0b100100100); // 1열
    ops.push_back(0b010010010); // 2열
    ops.push_back(0b001001001); // 3열

    // 대각선
    ops.push_back(0b100010001); // ↘
    ops.push_back(0b001010100); // ↙

    while (T--) {
        int start = 0;

        // 입력 받기 (H=0, T=1)
        for (int i = 0; i < 9; i++) {
            char c; 
            cin >> c;
            if (c == 'T') start |= (1 << (8 - i));
        }

        // BFS
        queue<pair<int,int>> q;
        vector<int> dist(512, -1);

        q.push({start, 0});
        dist[start] = 0;

        int answer = -1;

        while (!q.empty()) {
            auto [cur, d] = q.front(); q.pop();

            if (cur == 0 || cur == 511) { // 모두 H or 모두 T
                answer = d;
                break;
            }

            for (int mask : ops) {
                int nxt = cur ^ mask;
                if (dist[nxt] == -1) {
                    dist[nxt] = d + 1;
                    q.push({nxt, d + 1});
                }
            }
        }

        cout << answer << "\n";
    }
    return 0;
}
