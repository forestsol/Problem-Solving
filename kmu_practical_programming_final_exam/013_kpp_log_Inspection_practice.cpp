/***********************************************
 * 2025-06-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool is_valid(const string& s){
    if(s.size() > 100) return false;
    static const regex pattern(
        R"(^(line_name) : [A-Za-z]+ (product_name) : [A-Za-z]+ (error_level) : [A-Za-z]+ (message) : [A-Za-z]+$)"
    );
    return regex_match(s, pattern);
}

int main() {
    fastio;
    int tc;
    cin >> tc;
    string dummy;
    getline(cin, dummy);
    while(tc-- > 0){
        int n;
        cin >> n;
        string dummy;
        getline(cin, dummy);
        int cnt = 0;
        for(int i =0; i<n; i++){
            string s;
            getline(cin, s);
            if(!is_valid(s)){
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}