/***********************************************
 * 2025-09-02
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<int> origin;
vector<int> dp;

int main() {
    fastio;
    int n;
    cin >> n;
    origin.resize(n);
    dp.resize(n);
    for(int i = 0; i < n ; i++){
        cin >> origin[i];
    }
    
    for(int i = 0; i < n; i++){
        int check = origin[i];
        int count = 0;
        for(int j = 0; j < i; j++){
            if(check > origin[j]){
                if(dp[j] > count){
                    count = dp[j];
                }
            }
        }
        dp[i] = count + 1;
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}