/***********************************************
 * 2025-09-09
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int cnt = 0;
vector<vector<int>> friends;
vector<bool> visited;

void bfs(int s){
    queue<int> q;
    visited[s] = true;

    for(int v : friends[s]){
        if(!visited[v]){
            visited[v] = true;
            q.push(v);
            cnt++;
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : friends[u]){
            if(!visited[v]){
                visited[v] = true;
                cnt++;
            }
        }
    }
}

int main() {
    fastio;
    int n, m ;
    cin >> n >> m;
    friends.resize(n+1);
    visited.resize(n+1, false);
    for(int i = 0; i < m ; i++){
        int u, v;
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    bfs(1);

    cout << cnt << endl;

    // 알고리즘 문제 풀이 시작
    return 0;
}