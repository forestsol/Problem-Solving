/***********************************************
 * 2025-08-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    vector<vector<int>> connect(n+1);
    for(int i = 0 ; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    vector<int> parent(n+1, 0);
    queue<int> q;
    q.push(1);

    parent[1] = -1;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int next : connect[current]){
            if(parent[next] == 0){
                parent[next] = current;
                q.push(next);
            }
        }
    }

    for(int i = 2; i <= n; i++){
        cout << parent[i] << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}