/***********************************************
 * 2025-10-09
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool arr[988];

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int n;
    cin >> n;
    memset(arr, true, sizeof(arr));
    int cnt = 0;

    for(int i = 123; i<988; ++i){
        string temp = to_string(i);
        if(temp[0] == temp[1] || temp[1] == temp[2] || temp[2] == temp[0]){
            arr[i] = false;
        }
        if(temp[0] == '0' || temp[1] == '0' || temp[2] == '0'){
            arr[i] = false;
        }
    }

    for(int i=0; i<n; ++i){
        int ans, strk, ball;
        cin >> ans >> strk >> ball;

        for(int j=123; j<988; ++j){
            if(arr[j]){
                string cur = to_string(j);
                string ans_str = to_string(ans);

                int strk_cnt = 0;
                int ball_cnt = 0;

                for(int k=0; k<3; ++k){
                    for(int l=0; l<3; ++l){
                        if(k == l && cur[k] == ans_str[l]) strk_cnt++;
                        if(k != l && cur[k] == ans_str[l]) ball_cnt++;
                    }
                }

                if(strk != strk_cnt || ball != ball_cnt) arr[j] = false;
            }
        }       
    }
    for(int i=123; i<988; ++i){
        if(arr[i]){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}