/***********************************************
 * 2025-04-13
 * 002_백준_수들의 합 5
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    // 목표 :  N을 몇 개의 연속된 자연수의 합으로 나타내기

    int start = 1, end = 1; 
    int sum = 1, count = 0;

    while (start <= n){
        if (sum == n) count++; // 합이 n이면 발견한 것임 카운트 증가
        if (sum >= n){ // 합이 n보다 크면, 합에서 현재 시작 숫자를 빼서 나머지 숫자의 합만 놔두기
            sum -= start;
            start++;
        } else{ // 합이 n보다 작으면, 다음 숫자를 합에 더해 숫자가 하나 추가된 배열의 합을 만들기
            end++;            
            sum += end;
        }
    }
    cout << count << endl;

    return 0;
}