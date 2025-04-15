/***********************************************
 * 2025-04-15
 * 005_실전프로젝트-청백전-std
 ***********************************************/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

 bool isBipartite(int n, vector<vector<int>>& graph){
    vector<int> team(n+1, -1); // 0과 1로 어떤 팀에 속하는지 표현, -1은 배정안됨을 뜻함. // 0번 인덱스는 쓰지 않을 것이므로 n+1크기의 벡터 선언
    for(int i = 1; i <= n ; i++){ // i번 학생임. 1부터 시작하고 n까지 감. 인덱스보다 +1  // 모든 노드 n개를 직접 탐색(비연결 그래프 고려하기)
        if(team[i] == -1){ 
            queue<int> q; // bfs
            q.push(i);
            team[i] = 0;
            while(!q.empty()){
                int current = q.front();
                q.pop();

                for(int neighbor : graph[current]){ // current번 학생의 이웃을 쭉 검사
                    if (team[neighbor] == -1){ // 이웃 학생이 팀 배정이 안된 학생이라면?
                        team[neighbor] = 1 - team[current]; // 반대 색상으로 배정
                        q.push(neighbor);
                    }
                    else if (team[neighbor] == team[current]){
                        return false; // 이미 팀이 정해진 바로 옆 이웃이 나랑 같은 팀인 경우 -> 팀 구성 불가라는 뜻임.
                    }
                }
            }
        }
    }
    return true;
 }


int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m; // 학생수 n, 좋지 않은 관계의 수 m
        cin >> n >> m;

        vector<vector<int>> graph(n+1);        
        for(int i = 0; i < m; i++){
            int u, v; // 안좋은 관계
            cin >> u >> v;
            graph[u].push_back(v); // 주어지는 안좋은 관계를 각각 자신의 graph 노드에 기록해두기.
            graph[v].push_back(u);
        }

        if(isBipartite(n, graph)){
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    return 0;
}