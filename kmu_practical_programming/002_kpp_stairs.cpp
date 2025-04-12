/***********************************************
 * 2025-04-12
 * 002_실전프로젝트-계단오르기-std
 * 학우의 풀이가 좀 더 사실
***********************************************/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main(){
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, p; // 총 계단 수 n, 망가진 계단의 위치 p
        cin >> n >> p;
        int result;
        if(n % 2 == 1){ // 계단 갯수가 홀수인 경우, 무너지든 말든 올라가는 횟수 동일
            result = n / 2 + n % 2;
        }
        else{
            if(p % 2 == 1){ // 계단 갯수가 짝수인데, 홀수번째 계단이 무너지면 횟수 동일
                result = n / 2 + n % 2;
            }
            else{ // 계단 갯수가 짝수인데, 짝수번째 계단이 무너지면 횟수 + 1
                result = n / 2 + n % 2 + 1;
            }
        }
        cout << result << endl;    
    }
    return 0;
}
