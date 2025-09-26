/***********************************************
 * 2025-09-26
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    map<string, double> trees;
    string x;
    int total_trees = 0;
    while(getline(cin, x)){
        if(trees.find(x) != trees.end()){
            trees[x]++;
            total_trees++;
        }
        else{
            trees.insert({x, 1});
            total_trees++;
        }
    }
    for(auto t : trees){
        cout << t.first << " " << fixed << setprecision(4) << t.second / total_trees * 100 << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}