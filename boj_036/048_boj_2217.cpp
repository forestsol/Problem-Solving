    /***********************************************
     * 2025-08-25
     ***********************************************/

    #include <bits/stdc++.h>
    using namespace std;

    #define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #define endl '\n'

    int main() {
        fastio;
        int n;
        cin >> n;
        vector<int> ropes;
        for(int i = 0; i < n; i++){
            int rope;
            cin >> rope;
            ropes.push_back(rope);
        }
        sort(ropes.begin(), ropes.end(), greater<int>());
        int cnt = 0;
        int w = 0;
        for(auto r : ropes){
            cnt++;
            if(r * cnt >= w){
                w = r*cnt;
            }
        }
        cout << w << endl;
        // 알고리즘 문제 풀이 시작
        return 0;
    }