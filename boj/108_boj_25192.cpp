/***********************************************
 * 2025-10-18
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
    int cnt =0;
    set<string> people;
    for(int i = 0; i<n; ++i){
        string msg;
        cin >> msg;
        if(msg == "ENTER"){
            people.clear();
        }else{
            if(people.find(msg) == people.end()){
                cnt++;
                people.insert(msg);
            }
        }
    }
    cout << cnt << endl;

    // 알고리즘 문제 풀이 시작
    return 0;
}