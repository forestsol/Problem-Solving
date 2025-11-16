/***********************************************
 * 2025-10-18
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int n;
    cin >> n;
    map<string, bool> dance;
    dance.insert({"ChongChong", true});
    for(int i =0; i<n; i++){
        string p1, p2;
        cin >> p1 >> p2;
        if(dance.find(p1) != dance.end()){
            dance.insert({p2, true});
        }
        if(dance.find(p2) != dance.end()){
            dance.insert({p1, true});
        }
    }
    cout << dance.size() << endl;
    return 0;
}