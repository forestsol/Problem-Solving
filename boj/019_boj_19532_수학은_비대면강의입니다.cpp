/***********************************************
 * 2025-08-09
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f ;
    int flag = 0;
    for(int x = -999; x <= 999 ; ++x){
        for(int y = -999; y <= 999; ++y){
            if(a*x+b*y == c && d*x + e*y == f){
                cout << x << " " << y << endl;
                break;
                flag = 1;
            }
        if(flag == 1){
            break;
        }
        }

    }
    // 알고리즘 문제 풀이 시작
    return 0;
}