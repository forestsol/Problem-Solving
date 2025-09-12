/***********************************************
 * 2025-09-07
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int n;
    cin >> n;
    unordered_set<int> nums;
    for(int i= 0 ; i < n; i++){
        int num;
        cin >> num;
        nums.insert(num);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        if(nums.find(num) != nums.end()){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}