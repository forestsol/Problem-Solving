/***********************************************
 * 2025-04-15
 * 003_백준_2751_수_정렬하기_2
 * mergeSort 써보는 문제제
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

void mergeSort(vector<int>& arr, int left, int right, vector<int>& temp){
    //-----------------------------------
    // 종료조건
    if(left >= right) return;
    //-----------------------------------
    // 분할
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, temp);
    mergeSort(arr, mid + 1, right, temp);
    //-----------------------------------
    // 병합 시작

    int i = left; // 좌측 배열의 인덱스로 사용, 좌측 배열 중 가장 작은 값인 left 부터 시작
    int j = mid + 1; // 우측 배열의 인덱스로 사용, 우측 배열 중 가장 작은 값인 mid + 1부터 시작
    int k = left; // temp의 인덱스로 사용

    while(i <= mid && j <= right){ // 좌, 우 두 배열 중 하나를 모두 사용할 때 까지 진행
        if(arr[i] <= arr[j]){ // 좌, 우 두 값중 작은 값을 빼내어 임시 배열에 넣고, 뺀쪽의 인덱스를 증가시켜 다음 인덱스와 비교하기.
            temp[k] = arr[i]; // 임시배열에 넣기기
            k++; i++; // 인덱스 증가
        }
        else{
            temp[k] = arr[j];
            k++; j++;
        }
    }

    //-----------------------------------
    // 빼다가 한쪽을 다 쓰면, 남은 쪽은 여러개가 남아있을 것. 그 남은 여러개 다 빼와서 넣기.
    while(i <= mid){ 
        temp[k] = arr[i];
        k++; i++;
    }

    while(j <= right){
        temp[k] = arr[j];
        k++; j++;
    }

    //-----------------------------------
    // 임시 배열에 있는 정렬된 값들을 다시 원래 배열로 옮기기.
    // for(int l = left; l < right; l++){ // 틀린 코드
    for(int l = left; l <= right; l++){ // **중요** 여기서 틀렸음. right은 이미 N-1인 인덱스이기 때문에 순회할 때 right도 방문해야함.
        arr[l] = temp[l];
    }

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

    mergeSort(numbers, 0, N-1, temp); // 인덱스라서 1 뺌

    for(int i : numbers){
        cout << i << endl;
    }

    return 0;
}