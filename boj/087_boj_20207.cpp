/***********************************************
 * 2025-09-26
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> calander(367 ,0);
    for(int i = 0; i<n; i++){
        int s, e;
        cin >> s >> e;
        for(int d = s; d <= e; d++){
            calander[d]++;
        }
    }
    int width = 0, height = 0, answer = 0;
    for(int d = 1; d <= 366 ; d++){
        if(calander[d] > 0){
            width++;
            height = max(calander[d], height);
        }else{
            if(width > 0){
                answer += width * height;
                width = 0;
                height = 0;
            }
        }
    }
    if (width > 0) answer += width * height;

    cout << answer << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}