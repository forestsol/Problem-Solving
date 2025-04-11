#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

void bfs(int n, vector<vector<int>>& result){
    queue<pair<int, int>> q;
    q.push({n-1, 0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        result[x][y] += 1;
        q.pop();
    }

}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n; // 격자의 크기
        cin >> n;

        vector<string> map(n);
        for(int i = 0; i < n; i++){
            string s;
            getline(cin >> ws, s);
            map[i] = s;
        }
        // X는 빈칸으로 치지 않는다.
        // 인접한 경우 -> 바로 이동
        // 좌 우 두칸 세칸 떨어진 경우 -> 자신들 바로 위 빈칸, 자신들 사이 빈칸, 사이의 한칸 위도 빈칸
        // 위로 두칸 떨어진 경우 -> 두 개 사이가 빈칸
        // 대각선에 있는 경우 -> 자신의 위와 옆이 빈칸

    }
    return 0;
}