/***********************************************
 * 2025-04-13
 * 003_실전프로젝트-수고르기-std
 ***********************************************/
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n, m; // n개의 정수, 차이 m
        // 두 수의 차이가 m 이상인 것 중에 제일 작은 차이를 구하기기
        cin >> n >> m;
        vector<int> number(n);
        for(int i = 0 ; i < n; i++){
            cin >> number[i];
        }

        sort(number.begin(), number.end()); // 정럴해두기
        


        int start = 0, end = 1; // two_pointer
        int minus = INT_MAX; //int의 최댓값
        
        while(end < n){ // end가 인덱스 밖으로 넘어가면 안됨.
            int new_minus = number[end]-number[start];
            if(new_minus >= m){ // 두 차이가 m보다 크면 기록할 가능성 있음.
                // if(minus >= new_minus){ // 앞에 나온 것 보다 차이가 작을때만 기록.
                //     minus = new_minus;
                // }
                minus = min(minus, new_minus); // 위에 if문 보다 이게 훨 간결결
                start++;              
            }else{
                end++; 
            }
        }
        cout << minus << endl;
    }
    return 0;
}