/***********************************************
 * 2025-08-29
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int a, b;
    cin >> a >> b;
    map<int, int> as;
    int as_cnt = 0;
    int bs_cnt = 0;
    for(int i = 0; i < a; i++){
        int numa;
        cin >> numa;
        as.insert({numa,0});
        as_cnt++;
    }
    for(int j =0; j<b; j++){
        int numb;
        cin >> numb;
        if(as.find(numb) != as.end()){
            as_cnt--;
        }
        else{
            bs_cnt++;
        }
        
    }
    cout << as_cnt+bs_cnt << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}