#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited){
    queue<int> q; // 다음 방문지를 기록할 큐.
    q.push(start); // 첫 시작지점을 큐에 넣기.
    visited[start] = true; // 첫 시작지점은 방문했음.

    while(!q.empty()){ // 큐가 완전히 빌 때 까지 반복하기.
        int curr = q.front(); // 큐의 맨 앞 노드를 curr에 기록해두고
        q.pop(); // pop 해서 비우기.
        cout << curr << " ";
        // 아래부턴, 다음 레벨의 노드들을 큐에 기록하는 작업.
        for (int next : graph[curr]){ // curr 노드와 연결된 노드들을 꺼내기
            if (!visited[next]){ // 꺼낸 노드가 방문한 노드가 아니라면
                q.push(next); // 그 노드를 큐의 뒷쪽에 기록하기.
                visited[next] = true; 
            }
        }    
    }

}


int main() {
    fastio;

    int n = 5;
    vector<vector<int>> graph(n+1); // 0번 노드가 아닌, 1번 노드부터 탐색하므로 크기가 1커야함.
    graph[1] = {2, 4};
    graph[2] = {1, 3};
    graph[3] = {2, 5};
    graph[4] = {1};
    graph[5] = {3};

    vector<bool> visited(n+1, false);
     
    bfs(1, graph, visited); // 1번 노드부터 탐색
    
    return 0;
}