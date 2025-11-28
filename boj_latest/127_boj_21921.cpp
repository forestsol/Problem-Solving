/***********************************************
 * 2025-11-28
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int dayMax = 250000;
int n, x;
int days[dayMax];
int visit_max;
int visit_max_count;

void input(){
    visit_max = 0;
    visit_max_count = 0;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> days[i];
    }
    return;
}

void solution(){
    input();
    int sum = 0;
    for(int i=0; i<x; i++){
        sum += days[i];
    }
    if(sum > 0){
        visit_max = sum;
        visit_max_count = 1;
    }
    for(int i=0; i<n-x; i++){
        sum -= days[i];
        sum += days[i+x];
        if(sum > visit_max){
            visit_max = sum;
            visit_max_count = 1;
        }else if(sum == visit_max && sum != 0){
            visit_max_count++;;
        }
    }
    if(visit_max != 0){
        cout << visit_max << '\n' << visit_max_count << endl;
    }else{
        cout << "SAD" << endl;
    }
    return;
}

int main() {
    fastio;
    solution();
    // 알고리즘 문제 풀이 시작
    return 0;
}