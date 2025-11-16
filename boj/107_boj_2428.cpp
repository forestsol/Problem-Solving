/***********************************************
 * 2025-10-17
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
    vector<int> files;
    for(int i=0; i<n; ++i){
        int file;
        cin >> file;
        files.push_back(file);
    }
    sort(files.begin(), files.end());
    long long ans =0;
    int L = 0;
    for(int R =0; R<n; ++R){
        while(L < R && files[L] * 10LL < files[R] * 9LL) L++;
        ans += (R-L);
    }
    
    cout << ans << endl;
    return 0;
    // 알고리즘 문제 풀이 시작
    return 0;
}