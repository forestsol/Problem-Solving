/***********************************************
 * 2025-08-08
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    fastio;
    int n;
    cin >> n;
    vector<pair<int, int>> xy;
    for(int i = 0 ; i < n ; i++){
        int x, y;
        cin >> x >> y;
        pair<int, int> p = make_pair(x, y);
        xy.push_back(p);
    }
    sort(xy.begin(), xy.end(), compare);

    for(auto pair : xy){
        cout << pair.first << " " << pair.second << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}