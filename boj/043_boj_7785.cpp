/***********************************************
 * 2025-08-20
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n;
    cin >> n;
    map<string, string, greater<string>> listing;
    for(int i = 0 ; i < n ; i++){
        string name;
        string ox;
        cin >> name >> ox;
        if(ox == "enter"){
            listing.insert({name, ox});
        }
        if(ox == "leave"){
            if(listing.find(name) == listing.end()){
                continue;
            }
            else{
                listing.erase(name);
            }
        }
    }
    for(auto outmap : listing){
        cout << outmap.first << endl;
    }

    // 알고리즘 문제 풀이 시작
    return 0;
}