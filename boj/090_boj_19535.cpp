/***********************************************
 * 2025-09-30
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int Node_MAX = 3000001;

int n;
long long D_count = 0;
long long G_count = 0;
vector<int> tree[Node_MAX];
long long acnt[Node_MAX];

long long combi(long long n, long long r){
    if(r < 0 || r > n){
        return 0;
    }
    if(r > n/2){
        r = n-r;
    }

    long long result = 1;
    for(int i=1; i<=r; ++i){
        result = result * (n-i+1) / i;
    }
    return result;
}

int main() {
    fastio;
    cin >> n;
    for(int i=1; i<n; ++i){
        int parent, child;
        cin >> parent >> child;
        tree[parent].push_back(child);
        tree[child].push_back(parent);
        acnt[parent]++; acnt[child]++;
    }

    for(int u=1; u<=n; ++u){  // D_case
        for(auto v : tree[u]){
            if(u < v){
                long long d_u = acnt[u];
                long long d_v = acnt[v];

                D_count += (d_u - 1) * (d_v - 1);
            }
        }
    }

    for(int u=1; u<=n; ++u){  // G_case
        if(acnt[u] >= 3){
            G_count += combi(acnt[u], 3); 
        }
    }

    long long G_triple = G_count*3;
    if(D_count > G_triple){
        cout << 'D' << endl;
    } else if(D_count < G_triple){
        cout << 'G' << endl;
    } else if(D_count == G_triple) {
        cout << "DUDUDUNGA" << endl;
    }
    
    // 알고리즘 문제 풀이 시작
    return 0;
}