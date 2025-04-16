/***********************************************
 * 2025-04-15
 * 006_실전프로젝트-마트료시카정렬하기-std
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

long long mergeSort(vector<int>& arr, int left, int right, vector<int>& temp){
    if(left >= right){
        return 0;
    }
    int mid = (left + right) / 2;
    long long inv_count = 0;
    inv_count += mergeSort(arr, left, mid, temp);
    inv_count += mergeSort(arr, mid + 1, right, temp);

    int i = left;
    int j = mid + 1;
    int k = left;


}


int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n; // 인형의 갯수 2<= m <= 20000
        cin >> n;
        vector<int> doll(n); // 인형의 높이를 기록하는 배열
        vector<int> temp(n);

        for(int i = 0; i < n; i++){
            cin >> doll[i];
        }

        long long result = mergeSort(doll, 0, n, temp);
        cout << result << endl;
    }
    return 0;
}