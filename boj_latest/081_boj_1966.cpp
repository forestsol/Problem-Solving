/***********************************************
 * 2025-09-21
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'



int main() {
    fastio;
    int t;
    cin >> t;
    queue<pair<int,bool>> q;
    vector<int> priority;
    while(t-- >0){
        priority.clear();
        q = queue<pair<int,bool>>();
        int cnt = 0;
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(i == m){
                priority.push_back(num);
                q.push(make_pair(num, true));
            }else{
                priority.push_back(num);
                q.push(make_pair(num, false));
            }
        }
        sort(priority.begin(), priority.end(), greater<>());
        
        while(true){
            auto cur = q.front(); q.pop();
            if(cur.first != priority[0]){
                q.push(cur);
            }
            else{
                cnt++;
                priority.erase(priority.begin());
                if(cur.second == true){
                    cout << cnt << endl;
                    break;
                }
            }
        }
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}