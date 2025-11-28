/***********************************************
 * 2025-10-26
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int n;
    long long m;

    cin >> n >> m;

    vector<long long> trees(n);
    for(int i=0; i<n; ++i){
        cin >> trees[i];
    }

    long long left =0;
    long long right = *max_element(trees.begin(), trees.end());
    long long result =0;

    while(left <= right){
        long long mid = (left+right)/2;
        long long sum =0;

        for(auto t : trees){
            if(t>mid) sum += (t-mid);
        }

        if(sum>=m){
            result = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout << result << endl;
    return 0;
}