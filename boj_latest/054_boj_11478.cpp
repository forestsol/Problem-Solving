/***********************************************
 * 2025-08-29
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    string str;
    cin >> str;
    set<string> strsub;
    for(int i = 1; i <= str.length(); i++){
        for(int j = 0; j < str.length() - i + 1; j++){
             strsub.insert(str.substr(j, i));
        }
    }
    cout << strsub.size() << endl;

    // 알고리즘 문제 풀이 시작
    return 0;
}