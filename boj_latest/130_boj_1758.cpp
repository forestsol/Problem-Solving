/***********************************************
 * 2025-12-02
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> origins;
    for(int i = 0; i<n; i++){
        int origin;
        cin >> origin;
        origins.push_back(origin);
    }
    sort(origins.begin(), origins.end(), greater<>());
    long long tipMax = 0;
    for(int i =0; i < n; i++){
        int tip = origins[i] - i;
        if(tip < 0) tip = 0;
        tipMax += tip;
    }
    cout << tipMax << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}