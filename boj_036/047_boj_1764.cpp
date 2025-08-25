/***********************************************
 * 2025-08-24
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int cnt = 0;

    map<string, int> hear;
    map<string, int> hear_saw;
    
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        hear.insert({str,1});
    }
    for(int j = 0; j < n; j++){
        string str;
        cin >> str;
        if(hear.find(str) != hear.end()){
            cnt++;
            hear_saw.insert({str,1});
        }
    }
    cout << cnt << endl;
    for(auto hs : hear_saw){
        cout << hs.first << endl;
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}