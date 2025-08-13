/***********************************************
 * 2025-08-12
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool compare(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
    fastio;
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), compare);

    string prev;
    for(int i = 0 ; i < n ; i++){
        string current = arr[i];
        if(prev != current){
            cout << current << endl;
        }
        prev = current;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}