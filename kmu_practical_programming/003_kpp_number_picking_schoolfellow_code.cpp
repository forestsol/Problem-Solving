#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int a;
    cin >> a;

    while (a--) {
        int b, c;
        cin >> b >> c;
        vector<int> data(b);

        for (int i = 0; i < b; i++) {
            cin >> data[i];
        }

        sort(data.begin(), data.end());

        int ans = INT_MAX;
        int i = 0, j = 1;

        while (j < b) {
            if (data[j] - data[i] >= c) {
                ans = min(ans, data[j] - data[i]);
                i++;
            } else {
                j++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
