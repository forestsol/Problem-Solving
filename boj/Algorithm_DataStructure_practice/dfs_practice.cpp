#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited){
    visited[node] = true;
    cout << node << " ";

    for(int next : graph[node]){
        if(!visited[next]){
            dfs(next, graph, visited);
        }
    }
}

int main() {
    fastio;
    int n = 5;
    vector<vector<int>> graph(n+1);
    /*graph[1] = {2,4};
    graph[2] = {1,3};
    graph[3] = {2,5};
    graph[4] = {1};
    graph[5] = {3};*/
    // 아래와 같은 역할의 코드. push_back을 사용하냐 마냐.
    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[1].push_back(4);
    graph[4].push_back(1);

    graph[3].push_back(5);
    graph[5].push_back(3);

    vector<bool> visited(n+1, false);

    dfs(1, graph, visited);
    return 0;
}