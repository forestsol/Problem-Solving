/***********************************************
 * 2025-10-10
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<vector<char>> sea_map;

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int r, c;
    cin >> r >> c;

    int map_x_min = r;
    int map_x_max = 0;
    int map_y_min = c;
    int map_y_max = 0;

    sea_map.resize(r, vector<char>(c));
    for(int i=0; i<r; ++i){
        string s;
        cin >> s;
        for(int j=0; j<c; ++j){
            sea_map[i][j] = s[j];
        }
    }
    vector<pair<int, int>> next_chng;
    for(int i = 0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(sea_map[i][j] == 'X'){
                int near_sea_cnt = 0;
                for(int k=0; k<4; ++k){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx == -1 || nx == r || ny == -1 || ny == c || sea_map[nx][ny] == '.'){
                        near_sea_cnt++;
                    }
                }
                if(near_sea_cnt >= 3){
                    next_chng.push_back(make_pair(i, j));
                }
            }
        }
    }
    for(auto pos : next_chng){
        sea_map[pos.first][pos.second] = '.';
    }

    for(int i = 0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(sea_map[i][j] == 'X'){
                map_x_min = min(map_x_min, i);
                map_x_max = max(map_x_max, i);
                map_y_min = min(map_y_min, j);
                map_y_max = max(map_y_max, j);
            }
        }
    }

    for(int i = map_x_min; i <= map_x_max; ++i){
        for(int j = map_y_min; j <= map_y_max; ++j){
            cout << sea_map[i][j];
        }
        cout << endl;
    }

    return 0;
}