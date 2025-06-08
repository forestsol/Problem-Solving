/***********************************************
 * 2025-05-23
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
        vector<int> citation(n);
        for(int i = 0; i < n; ++i){
            cin >> citation[i];
        }

        sort(citation.begin(), citation.end(), greater<int>());

        int h_index = 0;

        for(int i = 0; i < n; ++i){
            if(citation[i] >= i+1){
                h_index = i+1;
            }
            else {
                break;
            }
        }
        cout << h_index << endl;
    }
    return 0;
}