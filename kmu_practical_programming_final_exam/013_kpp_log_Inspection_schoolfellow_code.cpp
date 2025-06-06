#include <bits/stdc++.h>
using namespace std;

bool is_valid(const string& s) {
    if (s.size() > 100) return false;
    static const regex pattern(
        R"(^(line_name) : ([A-Za-z]+) (product_name) : ([A-Za-z]+) (error_level) : ([A-Za-z]+) (message) : ([A-Za-z]+)$)"
    );
    return regex_match(s, pattern);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    string dummy; getline(cin, dummy);   
    while(t--) {
        int n;
        cin >> n;
        getline(cin, dummy);         
        int cnt{};
        for(int i{};i<n;++i) {
            string s;
            getline(cin, s);
            if(!is_valid(s)) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }
}