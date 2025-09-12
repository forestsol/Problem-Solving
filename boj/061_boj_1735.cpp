/***********************************************
 * 2025-09-05
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 알고리즘 문제 풀이 시작
    int num1, den1, num2, den2;
    cin >> num1 >> den1 >> num2 >> den2;
    int gcd1 = gcd(num1, den1);
    int gcd2 = gcd(num2, den2);
    num1 = num1 / gcd1;
    den1 = den1 / gcd1;
    num2 = num2 / gcd2;
    den2 = den2 / gcd2;

    int num3 = num1 * den2 + num2 * den1;
    int den3 = den1 * den2;

    int gcd3 = gcd(num3, den3);
    num3 = num3 / gcd3;
    den3 = den3 / gcd3;

    cout << num3 << " " << den3 << endl;
    return 0;
}