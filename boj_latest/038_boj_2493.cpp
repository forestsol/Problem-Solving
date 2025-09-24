/***********************************************
 * 2025-09-24
5
6 9 5 7 4
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    stack<pair<int,int>> tops;
    vector<int> result(n+1, 0);
    tops.push(make_pair(INT_MAX, 0));
    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        if(tops.top().first >= num){
            tops.push(make_pair(num, i));
        }
        else{
            while(tops.top().first < num){
                auto prev = tops.top(); tops.pop();
                result[prev.second] = tops.top().second;
            }
            tops.push(make_pair(num, i));
        }
    }
    while(tops.size() != 1){
        auto prev = tops.top(); tops.pop();
        result[prev.second] = tops.top().second;
    }

    for(int i = 1; i <= n; i++){
        cout << result[i] << " ";
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}