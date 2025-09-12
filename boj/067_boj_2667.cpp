/***********************************************
 * 2025-09-09
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int MAX = 25;
int flag = 1;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool visited[MAX][MAX];
int aptMap[MAX][MAX];

int n;

vector<int> cntArr;

void bfs(int x, int y){
    int cnt = 1;
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.emplace(x, y);

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                if(aptMap[nx][ny] != 0 && !visited[nx][ny]){
                    q.emplace(nx, ny);
                    aptMap[nx][ny] = flag;
                    visited[nx][ny] = true;
                    cnt++;
                }  
            }
        }
    }
    flag++;
    cntArr.push_back(cnt);
}
 
int main() {
    fastio;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            aptMap[i][j] = int(str[j]) - '0';
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n; j++){
            if(aptMap[i][j] != 0 && !visited[i][j]){
                bfs(i, j);
            }
        }
    }

    sort(cntArr.begin(), cntArr.end());

    cout << flag - 1  << endl;
    for(int a : cntArr){
        cout << a << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}