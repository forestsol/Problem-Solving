/***********************************************
 * 2025-09-24
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int convert(char cmd){
    if(cmd == 'q') return 1;
    else if(cmd == 'u') return 2;
    else if(cmd == 'a') return 3;
    else if(cmd == 'c') return 4;
    else if(cmd == 'k') return 5;
    else return 999;
}

int main() {
    fastio;
    int result = 0;
    vector<int> ducks;
    string sound;
    cin >> sound;
    for(int i=0; i < sound.length(); i++){
        int cmd = convert(sound[i]);
        if(cmd == 1){
            auto it = find(ducks.begin(), ducks.end(), 5);
            if(it != ducks.end()){
                ducks[it- ducks.begin()] = 1;
            }else{
                ducks.push_back(1);
            }
        }else{
            auto it = find(ducks.begin(), ducks.end(), cmd-1);
            if(it != ducks.end()){
                ducks[it - ducks.begin()] = cmd;
            }else{
                result = -1;
                break;
            }
        }
    }
    
    if(result != -1){
        for(auto a : ducks){
            if(a != 5){
                result = -1;
                break;
            }
            else{
                result++;
            }
        }   
    }
    
    cout << result << endl;
    
    // 알고리즘 문제 풀이 시작
    return 0;
}