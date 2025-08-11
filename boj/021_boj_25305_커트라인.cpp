/***********************************************
 * 2025-08-11
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<>());
    // for(int i = 0; i < n; i++){
    //     cout << arr[i] << endl;
    // }
    
    cout << arr[k-1] << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}