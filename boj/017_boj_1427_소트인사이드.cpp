/***********************************************
 * 2025-08-07
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool compare(int i, int j){
    return j < i;
}

int main() {
    fastio;
    int n ;
    cin >> n;
    vector<int> arr;
    while(n > 0){
        arr.push_back(n%10);
        n = n/10;   
    }
    // sort(arr.begin(), arr.end(), greater<>());
    sort(arr.begin(), arr.end(), compare);
    for(auto i : arr){
        cout << i;
    }
    
    // 알고리즘 문제 풀이 시작
    return 0;
}