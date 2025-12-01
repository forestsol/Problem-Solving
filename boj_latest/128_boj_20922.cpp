/***********************************************
 * 2025-11-28
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, k;
vector<int> a;
vector<int> cnt(100001, 0);

void input(){
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
}

void solution(){
    input();

    int left = 0;
    int answer = 0;

    for(int right = 0; right < n; ++right){
        int x = a[right];
        cnt[x]++;

        while(cnt[x] > k){
            cnt[a[left]]--;
            left++;
        }

        answer = max(answer, right-left + 1);
    }
    cout << answer << endl;
}

int main() {
    fastio;
    solution();
    // 알고리즘 문제 풀이 시작
    return 0;
}