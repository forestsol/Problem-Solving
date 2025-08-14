/***********************************************
 * 2025-08-14
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

// =====================
struct node{
    int parent;
    vector<int> child;
};

vector<node> tree;
vector<bool> deleted;
int leaf_count = 0;
// =====================
void dfs(int x){
    if(deleted[x]) return; // 종료조건
    int child_cnt = 0; 
    for(auto y : tree[x].child){
        if(!deleted[y]){
            child_cnt++;
            dfs(y);
        }
    }
    if(child_cnt == 0) leaf_count++;
}
// =====================
int main() {
    fastio;
    int n;
    cin >> n;

    tree.resize(n);
    deleted.assign(n, false);

    int root = -1;

    for(int i = 0 ; i < n ; i++){
        int p;
        cin >> p;
        tree[i].parent = p;
        if(p == -1) root = i;
        else tree[p].child.push_back(i);
    }
    
    int del_num;
    cin >> del_num;
    
    queue<int> q;

    q.push(del_num);
    deleted[del_num] = true;


    while(!q.empty()){
        int num = q.front();
        q.pop();
        for(auto a : tree[num].child){
            deleted[a] = true;
            q.push(a);
        }
    }
    if(!deleted[root]){
        dfs(root);
    }

    cout << leaf_count << endl;
    // 알고리즘 문제 풀이 시작
    return 0;
}