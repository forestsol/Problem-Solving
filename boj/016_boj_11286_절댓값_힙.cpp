/***********************************************
 * 2025-08-06
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main() {
    fastio;
    int n, x;
    
    priority_queue<int, vector<int>, cmp> q;
    vector<int> v;

    cin >> n;

    for(int i = 0 ; i < n; ++i){
        cin >> x;
        if(x == 0){
            if(q.empty()){
                v.push_back(0);
            }else{
                v.push_back(q.top());
                q.pop();
            }
        }else{
            q.push(x);
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }

    return 0;
}