/***********************************************
 * 2025-09-08
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int MAX = 101;
int computers[MAX][MAX];
bool visited[MAX];
int n, m; // 컴퓨터수 n, 쌍의 수 m
int cnt = -1;

void dfs(int u){
    visited[u] = true;
    cnt++;
    for(int v = 1; v <= n ; v++){
        if(computers[u][v] && !visited[v]){
            dfs(v);
        }
    }
}

int main() {
    fastio;
    cin >> n >> m;

    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u >> v;
        computers[u][v] = 1;
        computers[v][u] = 1;
    }
    dfs(1);
    cout << cnt << endl;

    // 알고리즘 문제 풀이 시작
    return 0;
}