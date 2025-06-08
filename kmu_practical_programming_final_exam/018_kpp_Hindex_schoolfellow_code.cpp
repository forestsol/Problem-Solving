#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++) {
        int n;
        cin >> n;

        vector<int> citation(n);

        for (int i = 0; i < n; i++) {
            cin >> citation[i];
        }

        sort(citation.rbegin(), citation.rend());

        int h_index = 0;

        for (int i = 0; i < n; i++) {
            if (citation[i] >= i + 1) {
                h_index = i + 1;
            } else {
                break;
            }
        }

        cout << h_index << endl;
    }

    return 0;
}
