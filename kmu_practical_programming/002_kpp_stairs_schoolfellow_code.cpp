#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t --> 0)
    {
        int n, p;
        cin >> n >> p;

        int result = (p - 1) / 2 + (p - 1) % 2; // 전체 계단을 p를 기준으로 나누었을 때 아랫쪽
        result += (n - (p - 1)) / 2 + (n - (p - 1)) % 2; // 전체 계단을 p를 기준으로 나누었을 때 윗쪽

        cout << result << endl;
    }
    return 0;
}