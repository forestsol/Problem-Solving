/***********************************************
 * 2025-04-27
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
        map<int, pair<int, int>> arrays; // key : 배열 번호, value : (배열의 현재 크기, 배열에 실제로 들어있는 원소 수)
        long long totalCopied = 0; // 복사된 총 원소 갯수(답)

        int n; // 데이터 입력 횟수
        cin >> n;
        for(int i = 0; i < n; i++){
            int a, c; // 배열의 번호 a, 입력될 데이터 수 c
            cin >> a >> c;
            int currCapacity = arrays[a].first;
            int currSize = arrays[a].second;

            int newSize = currSize + c;

            if(newSize > currCapacity){
                int newCapacity = 1;
                while(newCapacity < newSize){
                    newCapacity *= 2;
                }

                totalCopied += currSize;
                currCapacity = newCapacity;
            }

            currSize = newSize;
            arrays[a] =  {currCapacity, currSize}; // pair 도 이런식으로 넣으면 됨.
        }
        cout << totalCopied << endl;
    }
    return 0;
}