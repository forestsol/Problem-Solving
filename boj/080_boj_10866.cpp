/***********************************************
 * 2025-09-21
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

unordered_map<string, int> table = {
    {"push_front", 1},
    {"push_back", 2},
    {"pop_front", 3},
    {"pop_back", 4},
    {"size", 5},
    {"empty", 6},
    {"front", 7},
    {"back", 8},
};

deque<int> dq;

int main() {
    fastio;
    int n;
    cin >> n;
    while(n-- >0){
        string cmd;
        int val;

        cin >> cmd;

        switch(table[cmd]){
            case 1:
                cin >> val;
                dq.push_front(val);
                break;
            case 2:
                cin >> val;
                dq.push_back(val);
                break;
            case 3:
                if(!dq.empty()){
                    int cur = dq.front(); dq.pop_front();
                    cout << cur << endl;
                }else{
                    cout << -1 << endl;
                }
                break;
            case 4:
                if(!dq.empty()){
                    int cur = dq.back(); dq.pop_back();
                    cout << cur << endl;
                }else{
                    cout << -1 << endl;
                }
                break;
            case 5:
                cout << dq.size() << endl;
                break;
            case 6:
                if(!dq.empty()){
                    cout << 0 << endl;
                }else{
                    cout << 1 << endl;
                }
                break;
            case 7:
                if(!dq.empty()){
                    int cur = dq.front();
                    cout << cur << endl;
                }else{
                    cout << -1 << endl;
                }
                break;
            case 8:
                if(!dq.empty()){
                    int cur = dq.back();
                    cout << cur << endl;
                }else{
                    cout << -1 << endl;
                }
                break;
        }

    }

    // 알고리즘 문제 풀이 시작
    return 0;
}