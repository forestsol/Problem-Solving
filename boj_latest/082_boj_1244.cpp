/***********************************************
 * 2025-09-22
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> switchs(n);
    for(int i = 0 ; i < n ; i++){
        cin >> switchs[i]; 
    }    
    int students;
    cin >> students;
    for(int i = 0; i < students; ++i){
        int gen, num;
        cin >> gen >> num;
        if(gen == 1){
            for(int j = num - 1; j < n; j+=num){
                switchs[j] ^= 1;
            }
        }else{
            switchs[num-1] ^= 1;
            int l = num -2;
            int r = num;
            while(l >= 0 && r < n && switchs[l] == switchs[r]){
                switchs[l] ^= 1;
                switchs[r] ^= 1;
                l--; r++;
            }
        }
    }
    for(int i = 0; i<n; i++){
        cout << switchs[i] << " ";
        if(i % 20 == 19) cout << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}