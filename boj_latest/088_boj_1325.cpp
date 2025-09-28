/***********************************************
 * 2025-09-29
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int computer_MAX = 10001;
int n, m;
vector<int> graph[computer_MAX];

int bfs(int start){
    int cnt = 1;
    vector<bool> visited(n+1, false);
    visited[start] = true;

    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        for(int next : graph[cur]){
            if(!visited[next]){
                visited[next] = true;
                cnt++;
                q.push(next);
            }
        }
    }
    return cnt;
}

int main() {
    fastio;
    cin >> n >> m;
    int max_hack = 0;
    set<int> computer_nums;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        int cnt = bfs(i);
        if(cnt == max_hack){
            computer_nums.insert(i);
        }
        else if(cnt > max_hack){
            max_hack = cnt;
            computer_nums.clear();
            computer_nums.insert(i);
        }
    }

    for(auto result : computer_nums){
        cout << result << " ";
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}