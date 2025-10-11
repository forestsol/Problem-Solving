/***********************************************
 * 2025-10-06
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

unordered_map<string, int> table = {
    {"push", 1},
    {"pop", 2},
    {"size", 3},
    {"empty", 4},
    {"front", 5},
    {"back", 6},
};

queue<int> q;

int main() {
    fastio;
    int n;
    cin >> n;
    while(n--){
        string cmd; int n;
        cin >> cmd;

        switch(table[cmd]){
            case 1:
                cin >> n;
                q.push(n);
                break;
            case 2:
                if(!q.empty()){
                    cout << q.front() << endl;
                    q.pop();
                }else{
                    cout << -1 << endl;
                }                
                break;
            case 3:
                cout << q.size() << endl;
                break;
            case 4:
                if(q.empty()){
                    cout << 1 << endl;
                }else{
                    cout << 0 << endl;
                }
                break;
            case 5:
                if(!q.empty()){
                    cout << q.front() << endl;
                }else{
                    cout << -1 << endl;
                }
                break;
            case 6:
                if(!q.empty()){
                    cout << q.back() << endl;
                }else{
                    cout << -1 << endl;
                }
                break;
        }
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}