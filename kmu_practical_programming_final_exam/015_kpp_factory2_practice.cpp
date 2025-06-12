/***********************************************
 * 2025-06-13
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

void print128(__int128 x){
    if(x == 0) {cout << '0'; return;}
    string s;
    while(x>0){
        s.push_back(char('0' + x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--> 0){
        int n;
        cin >> n;

        queue<ull> qa, qb;
        __int128 remA = 0, remB = 0;

        for(int i = 0; i < n; i++){
            string cmd;
            cin >> cmd;
            if(cmd == "ORDER"){
                ull x;
                char which;
                cin >> x >> which;
                if(which == 'A'){
                    qa.push(x);
                    remA += x;
                }
                else if(which == 'B'){
                    qb.push(x);
                    remB += x;
                }
                else{
                    if(remA <= remB){
                        qa.push(x);
                        remA += x;
                    }
                    else{
                        qb.push(x);
                        remB += x;
                    }
                } 
            }
            else{
                char which;
                cin >> which;
                if(which == 'A'){
                    ull y = qa.front();
                    qa.pop();
                    remA -= y;
                }             
                else{
                    ull y = qb.front();
                    qb.pop();
                    remB -= y;
                }   
            }
        }

        print128(remA);
        cout << ' ';
        print128(remB);
        cout << '\n';

    }
    return 0;
}