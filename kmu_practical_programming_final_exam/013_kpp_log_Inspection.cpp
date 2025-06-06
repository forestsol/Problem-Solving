/***********************************************
 * 2025-06-02
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
    int t;
    cin >> t;
    string dummy; getline(cin, dummy);
    while(t --> 0){
        int n;
        cin >> n;
        string dummy; getline(cin, dummy);
        int cnt{};

        for(int i{}; i < n; ++i){
            string s;
            getline(cin, s);
            if(!is_valid(s)){
                ++cnt;
            }
        }        
        cout << cnt << endl;

    }

    return 0;
}