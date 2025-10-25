/***********************************************
 * 2025-10-09
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    string a, b;
    cin >> a >> b;

    #include <boost/multiprecision/cpp_int.hpp>
    using namespace boost::multiprecision;

    cpp_int A(a), B(b);
    cout << a+b << '\n' << a-b << '\n' << a*b << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}