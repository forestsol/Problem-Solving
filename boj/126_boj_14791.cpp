/***********************************************
 * 2025-11-26
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int h, w;

int computeRain(pair<int, int> value0, pair<int, int> value1 ,pair<int, int> value2){
    int width = value0.second - value2.second - 1;
    int height = min(value0.first, value2.first) - value1.first;
    return width * height;
}

void solution(){
    cin >> h >> w;
    int rain = 0;
    stack<pair<int,int>> stk; // first = value, second = index
    for(int i=0; i<w; i++){
        int cur;
        cin >> cur;
        pair<int,int> value0 = make_pair(cur, i);
        if(stk.empty()){
            stk.push(value0);
        }else{
            auto value1 = stk.top(); stk.pop();
            if(value1.first > value0.first){
                stk.push(value1);
                stk.push(value0);
            }else if(value1.first == value0.first){
                stk.push(value0);                
            }else{
                while(!stk.empty()){
                    auto value2 = stk.top(); stk.pop();
                    rain += computeRain(value0, value1, value2);
                    if(value2.first > value0.first){
                        stk.push(value2);
                        break;
                    }else if(value2.first == value0.first){
                        break;
                    }else{
                        value1 = value2;
                    }
                }
                stk.push(value0);
            }
        }
    }
    cout << rain << endl;
}

int main() {
    fastio;
    solution();
    // 알고리즘 문제 풀이 시작
    return 0;
}