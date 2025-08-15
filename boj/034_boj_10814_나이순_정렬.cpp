/***********************************************
 * 2025-08-14
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;

    vector<pair<int, string>> arr;
    arr.reserve(n);

    for(int i = 0 ; i < n ; i++){
        int age;
        string name;
        cin >> age >> name;
        arr.emplace_back(age,name);
    }   
    stable_sort(arr.begin(), arr.end(),[](const pair<int, string>& a, const pair<int, string>& b){
        return a.first < b.first;
    });

    for(auto &p : arr){ 
        cout << p.first << " " << p.second << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}