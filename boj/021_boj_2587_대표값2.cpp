/***********************************************
 * 2025-08-10
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    vector<int> arr;
    int sum = 0;
    for(int i = 0; i<5 ; ++i){
        int num;
        cin >> num;
        sum += num;
        arr.push_back(num);
    }
    int avg = sum / 5;
    sort(arr.begin(), arr.end(), less<>());
    cout << avg << endl;
    cout << arr[2] << endl;


    // 알고리즘 문제 풀이 시작
    return 0;
}