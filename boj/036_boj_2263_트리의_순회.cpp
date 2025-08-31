/***********************************************
 * 2025-08-15
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<int> inorder, postorder;
map<int, int> pos;

void preorder(int in_start, int in_end, int post_start, int post_end){
    if(in_start > in_end || post_start > post_end){
        return;
    }
    int root = postorder[post_end];

    cout << root << " ";

    int root_inorder_idx = pos[root];
    
    int left_size = root_inorder_idx - in_start;
    
    preorder(in_start, root_inorder_idx -1, post_start, post_start + left_size - 1);
    preorder(root_inorder_idx + 1, in_end, post_start + left_size, post_end - 1);
}


int main() {
    fastio;
    int n;
    cin >> n;

    inorder.resize(n);
    postorder.resize(n);

    for(int i = 0 ; i < n ; ++i){
        cin >> inorder[i];
        pos[inorder[i]] = i; // i가 인덱스
    }
    for(int i = 0; i < n; ++i){
        cin >> postorder[i];
    }

    preorder(0, n-1, 0, n-1);
    
    // 알고리즘 문제 풀이 시작
    return 0;
}