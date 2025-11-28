/***********************************************
 * 2025-10-22
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

string field[5] = {"@   @", "@  @ ","@@@  ", "@  @ ","@   @"};

int main() {
    fastio;
    int n;
    cin >> n;
    
    for(string s : field){
        string out;
        
        for(char c : s){
            if(c == '@'){
                for(int i =0; i<n; ++i){
                    out.push_back('@');
                }
            }else{
                for(int i =0; i<n; ++i){
                    out.push_back(' ');
                }
            }
        }

        while (!out.empty() && out.back() == ' ') out.pop_back();

        for(int j =0; j<n; ++j){
            cout << out << endl;
        }
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}