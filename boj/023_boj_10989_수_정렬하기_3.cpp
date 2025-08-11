/***********************************************
 * 2025-08-11
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> arr(10001, 0);
    for(int i = 0 ; i < n ; ++i){
        int num;
        cin >> num;
        arr[num] += 1;
    }

    for(int i = 1; i <= 10000; i++){
        if(arr[i] != 0){
            for(int j = 0; j < arr[i]; j++){
                cout << i << endl;
            }
        }
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}