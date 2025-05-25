/***********************************************
 * 2025-05-23
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
        int n; // 스프링클러 개수
        cin >> n;
        long int minpos = 0;
        int maxval = 0;
        vector<int> arr(200000, 0);
        vector<long int> indexs(n);
        for(int i = 0; i < n; ++i){
            int origin;
            cin >> origin;
            int idx = origin + 100000;
            indexs[i] = idx;
        }
        for(int i = 0; i < n; ++i){
            int range;
            cin >> range;
            for(int j = indexs[i] - range; j <= indexs[i] + range; j++){
                arr[j] += 1;
                if(arr[j] == maxval){
                    if(j <= minpos){
                        minpos = j;
                    }
                }
                if(arr[j] > maxval){
                    maxval = arr[j];
                    minpos = j;
                }
            }
        }
        cout << minpos - 100000 << endl;
        
    }
    return 0;
}