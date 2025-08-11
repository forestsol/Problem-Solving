/***********************************************
 * 2025-08-09
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> arr;

    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    for(int i = 0; i < n; ++i){
        int temp = arr[i];
        int min = arr[i];
        int min_pos = i;
        for(int j= i+1; j < n; ++j){
            if(min > arr[j]){
                min = arr[j];
                min_pos = j;
            }
        }
        arr[i] = min;
        arr[min_pos] = temp;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}