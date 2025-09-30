/***********************************************
 * 2025-09-25
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    
    int t; cin >> t;
    while(t--){
        multiset<long long> s;
        int k; cin >> k;

        for(int i = 0; i < k; i++){
            char cmd;
            long long val;
            cin >> cmd >> val;
            if(cmd == 'I'){
                s.insert(val);
            }else{
                if(s.empty()) continue;
                if(val == 1){
                    auto it = prev(s.end());
                    s.erase(it);
                }else{
                    s.erase(s.begin());
                }
            }
        }

        if(s.empty()){
            cout << "EMPTY" << endl;
        }
        else{
            cout << *prev(s.end()) << " " << *s.begin() << endl;
        }


    }
    // 알고리즘 문제 풀이 시작
    return 0;
}