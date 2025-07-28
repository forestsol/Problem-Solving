/***********************************************
 * 2025-06-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc-- > 0){
        int n;
        cin >> n;
        vector<int> cit(n);
        for(int i = 0; i < n; i++){
            cin >> cit[i];
        }
        sort(cit.rbegin(), cit.rend());

        int h_index = 0;

        for(int i = 0; i < n; i++){
            if(cit[i] >= i+1){
                h_index = i+1;
            }
            else{
                break;
            }
        }
        cout << h_index << endl;
    }
    return 0;
}