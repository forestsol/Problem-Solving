/***********************************************
 * 2025-10-26
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> titles(n);
    for(int i=0; i<n; i++){
        cin >> titles[i].first >> titles[i].second;
    }
    for(int i=0; i<m; i++){
        int power;
        cin >> power;

        int left = 0;
        int right = n-1;

        while(left < right){
            int mid = (left + right) / 2;
            if(power <= titles[mid].second){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        cout << titles[left].first << endl;
    }
    return 0;
}