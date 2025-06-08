#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int c, k, p, m;
        cin >> c >> k >> p >> m;
        vector<int> v(p);
        for (int i = 0; i < p; i++) {
            cin >> v[i];
        }
        int x = 0;
        while (x < p && v[x] > k) ++x;
        if (x < m) {
            cout << 0 << "\n";
            continue;
        }
        int t_reduce = x - (m - 1);
        vector<int> diffs;
        diffs.reserve(x);
        for (int i = 0; i < x; i++) {
            diffs.push_back(v[i] - k);
        }
        sort(diffs.begin(), diffs.end());
        ll need = 0;
        for (int i = 0; i < t_reduce; i++) {
            need += diffs[i];
        }
        vector<int> caps;
        caps.reserve(p - x);
        for (int i = x; i < p; i++) {
            if (v[i] < k) {
                caps.push_back(k - v[i]);
            }
        }
        sort(caps.begin(), caps.end(), greater<int>());

        ll provided = 0;
        int b = 0;
        while (b < (int)caps.size() && provided < need) {
            provided += caps[b++];
        }
        if (provided < need) {
            cout << -1 << "\n";
        } else {
            cout << (t_reduce + b) << "\n";
        }
    }
    return 0;
}
