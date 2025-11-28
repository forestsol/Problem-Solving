/***********************************************
 * 2025-11-14
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, m;

bool visited[9];
int permutation[9];

void input(){
    cin >> n >> m;
}

void printPermutation(){
    for(int i=0; i<m; i++){
        cout << permutation[i] << ' ';
    }
    cout << endl;
}

void makePermutation(int n, int m, int depth){
    if(m == depth){
        printPermutation();
        return;
    }
    for(int i=1; i<=n; ++i){
        if(!visited[i]){
            visited[i] = true;
            permutation[depth] = i;
            makePermutation(n, m, depth+1);
            visited[i] = false;
        }
    }
}

void Solve(){
    input();
    makePermutation(n, m, 0);
}

int main() {
    fastio;
    Solve();
    return 0;
}