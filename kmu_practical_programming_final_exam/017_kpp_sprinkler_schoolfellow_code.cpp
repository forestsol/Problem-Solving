#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++) {
        int n;
        cin >> n;

        vector<int> position(n);
        vector<int> range(n);

        for (int i = 0; i < n; i++) {
            cin >> position[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> range[i];
        }

        vector<pair<int, int>> events;

        for (int i = 0; i < n; i++) {
            int left = position[i] - range[i];
            int right = position[i] + range[i];
            events.push_back({left, 1});
            events.push_back({right + 1, -1});
        }

        sort(events.begin(), events.end());

        int current_water = 0;
        int max_water = 0;
        int answer_position = 0;

        for (auto event : events) {
            current_water += event.second;

            if (current_water > max_water) {
                max_water = current_water;
                answer_position = event.first;
            }
        }

        cout << answer_position << endl;
    }

    return 0;
}
