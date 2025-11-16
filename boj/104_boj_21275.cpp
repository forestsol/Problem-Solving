/***********************************************
 * 2025-10-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int MAX_DIGIT = 36;

int findMinDigit(string str){  // a같은 문자가 들어간 문자열로 10진법 아래의 진법으로 검사를 할 수 없어서 이 함수가 필요함.
    int digit = 0;
    for(int i = 0; i < str.length(); ++i){
        if(str[i] >= '0' && str[i] <= '9'){
            digit = max(digit, str[i] - '0'); // 10진법까지 2진법이면 digit은 1이 들어가게 됨. 2진법의 최댓값은 1이니까.
        }else{
            digit = max(digit, str[i] - 'a' + 10); // 10진법 이상
        }
    }
    return max(2, digit+1); // 최소 진법은 2진법부터,
}

ll changeDecimalNumber(string str, int digit){
    ll result = 0;
    for(int i = 0; i < str.length(); ++i){
        int num;
        if(str[i] >= '0' && str[i] <= '9'){
            num = str[i] - '0';
        }else{
            num = str[i] - 'a' + 10;
        }
        result += num * pow(digit, str.length() - i - 1); // 2진수 4자리의 값을 10진수로 바꾸려면, 2의 3승 곱하기 그 자리의 수.
    }
    return result;
}


int main() {
    fastio;

    ll X;
    int A, B;

    string strA, strB;

    cin >> strA >> strB;

    int digit_A = findMinDigit(strA);
    int digit_B = findMinDigit(strB);

    int cnt = 0;
    for(int i = digit_A; i<= MAX_DIGIT; ++i){
        for(int j = digit_B; j<= MAX_DIGIT; ++j){
            ll change_A = changeDecimalNumber(strA, i);
            ll change_B = changeDecimalNumber(strB, j);
            if(i != j && change_A == change_B){
                cnt++;
                X = change_A;
                A = i;
                B = j;
            }
        }
    }

    if(cnt == 0){
        cout << "Impossible";
    } else if(cnt == 1){
        cout << X << ' ' << A << ' ' << B;
    } else {
        cout << "Multiple";
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}