/***********************************************
 * 2025-04-15
 * 003_백준_2751_수_정렬하기_2
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

void mergeSort(vector<int>& arr, int left, int right, vector<int>& temp){
    
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, temp);
    mergeSort(arr, mid + 1, right, temp);


}

int main() {
    fastio;
    int N;
    cin >> N;
    vector<int> numbers(N);
    vector<int> temp(N);
    for(int i = 0; i < N; i++){
        cin >> numbers[i];
    }

    mergeSort(numbers, 0, N-1, temp);

    return 0;
}