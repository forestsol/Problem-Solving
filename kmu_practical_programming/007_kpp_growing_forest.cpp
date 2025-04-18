/***********************************************
 * 2025-04-17
 * 007_실전프로젝트-숲가꾸기-std
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m, k, p;
        cin >> n >> m >> k >> p; // 총 격자의 크기 n, 나무의 수 m, 지력 회복 크기 k, 시뮬레이션 반복 횟수 p
        for(int i = 0; i < m; i++){
            int r, c, o; // 나무의 좌표 <r, c> , 나무의 나이 o
            cin >> r >> c >> o;
        }
    }
    // 시뮬레이션 결과 남아있는 나무 수 출력.
    return 0;
}