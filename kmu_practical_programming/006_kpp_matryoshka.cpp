/***********************************************
 * 2025-04-15
 * 006_실전프로젝트-마트료시카정렬하기-std
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

long long mergeSort(vector<int>& arr, int left, int right, vector<int>& temp){
    // 최악의 경우, 완전 내림차순을 올림차순으로 바꾸면서 역순 쌍 갯수가 int 범위를 초과할 수 있기 때문에 long long 사용
    if(left >= right){
        return 0;
    }
    int mid = (left + right) / 2;
    long long inv_count = 0; // inversion count: 역순 쌍의 갯수라는 뜻. 역순 쌍의 갯수를 발견한 만큼 자리를 바꿔서 오름차순으로 정렬함.
    inv_count += mergeSort(arr, left, mid, temp);
    inv_count += mergeSort(arr, mid + 1, right, temp);

    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv_count += mid - i + 1; 
            // 예를 들어보자, 1, 4, 6, 2, 3, 5 순열이 있음. 1,4,6 / 2,3,5 가 정렬이 되어있고,
            // 이 상태에서 temp에 집어넣을 때,
                // 1과 2를 비교 -> 자리 바꿀 필요 없음. 
                // 4와 2를 비교 -> 자리를 바꿔야 함.
                    // 이때 원래 순열 1, 4, 6, 2, 3, 5 를 보았을 때, 2는 왼쪽으로 인접한 인형과 2번 자리바꾸면서 이동함.
                    // 1, 4, 6, 2, 3, 5
                    // 1, 4, 2, 6, 3, 5
                    // 1, 2, 4, 6, 3, 5
                // 즉, 왼쪽에 정렬되지 않고 남은 갯수만큼 자리 교대를 하는 것(정렬 되지 않고 남은 갯수만큼 역순 쌍을 만들 수 있음.(6, 2 교대)(4, 2 교대))
                // 따라서 정렬되지 않고 남은 갯수 = mid(전체 갯수) - i(정렬된 갯수) + 1(인덱스를 갯수로 전환) 하는 식이 만들어 지는 것임.
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }

    for(int l = left; l <= right; l++){
        arr[l] = temp[l];
    }
    return inv_count;
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

        long long result = mergeSort(doll, 0, n-1, temp);
        cout << result << endl;
    }
    return 0;
}