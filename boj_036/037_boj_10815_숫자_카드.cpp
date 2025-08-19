/***********************************************
 * 2025-08-16
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;

    set<int> s;
    for(int i = 0 ; i < n; i++){
        int num;
        cin >> num;
        s.insert(num);
    }

    int m;
    cin >> m;
    for(int j = 0 ; j < m; j++){
        int num;
        cin >> num;
        if(s.find(num) != s.end()){
            cout << 1 ;
        }
        else{
            cout << 0 ;
        }
        if(j != m-1) cout << " ";
    }
    
    // 알고리즘 문제 풀이 시작
    return 0;
}