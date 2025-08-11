/***********************************************
 * 2025-08-11
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    fastio;
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i = 0; i < n ; ++i){
        int x, y;
        cin >> x >> y;
        pair<int, int> nums = make_pair(x,y);
        arr.push_back(nums);
    }

    sort(arr.begin(), arr.end(), compare);

    for(int i = 0; i < n ; ++i){
        cout << arr[i].first << " " << arr[i].second << endl;
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}