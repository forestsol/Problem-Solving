/***********************************************
 * 2025-10-02
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, m, v;
const int node_max = 1001;

vector<int> graph[node_max];
int dfs_visited[node_max];

void dfs(int u){
    dfs_visited[u] = true;
    cout << u << " ";
    for(int v : graph[u]){
        if(!dfs_visited[v]){
            dfs(v);
        }
    }
}

void bfs(int start){
    vector<bool> bfs_visited(n+1, false);
    bfs_visited[start] = true;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << " ";
        for(int next : graph[cur]){
            if(!bfs_visited[next]){
                bfs_visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    fastio;
    cin >> n >> m >> v;

    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int u = 1; u <= n; u++) {
        sort(graph[u].begin(), graph[u].end());
    }

    dfs(v);
    cout << endl;
    bfs(v);

    // 알고리즘 문제 풀이 시작
    return 0;
}