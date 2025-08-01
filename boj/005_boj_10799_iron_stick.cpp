/***********************************************
 * 2025-07-29
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    // 하나의 쇠막대기 위에 올라가는 쇠막대기는, 온전히 올라간다 => 레이저 좌 우의 막대기 수가 같다.
    // => 잘려도 이전과 차이가 없다.
    // 올라가 있는 쇠막대기 하나가 온전히 끝나는 경우( '))' ), 달라진다.
    string sticks;
    cin >> sticks;
    stack<char> stack;
    int result = 0;
    char prev = '0';

    for(int i = 0; i < sticks.length(); i++){
        if(sticks[i] == '('){
            stack.push(sticks[i]); // 레이저가 만들어지기 전 쌓인 쇠막대기 갯수
        }
        else{
            if(prev == '('){ // 레이저
                stack.pop(); // 레이저도 '(' 로 카운팅 되면 안되니까 팝 한번 먼저
                result += stack.size();
            }
            else if(prev == ')'){ // 쇠막대기의 끝지점
                stack.pop();
                result += 1;
            }
        }
        prev = sticks[i];
    }
    
    cout << result << endl;
    return 0;
}