/***********************************************
 * 2025-08-22
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int main() {
    fastio;
    int n, m;
    cin >> n >> m;

    map<string, int> pks;
    vector<string> pokemon;
    pokemon.push_back("garbage");  // 인덱스 맞춰주기 위해 가비지 넣음.
    
    for(int i = 1 ; i <= n; i++){
        string pk_name;
        cin >> pk_name;
        pks.insert({pk_name, i});
        pokemon.push_back(pk_name);
    }
    for(int j = 0 ; j < m; j++){
        string problem;
        cin >> problem;
        if(isdigit(problem[0]) != 0){  // isdigit(문자) 함수 : 들어온 문자가 0~9의 숫자인지 판별. 숫자라면 0이 아닌 값을 반환, 숫자가 아니라면 0을 반환.
            int idx = stoi(problem);
            cout << pokemon[idx] << endl;
        }
        else{
            cout << pks.find(problem)->second << endl;  // -> 연산자 : 이터레이터가 가리키는 요소에 접근가능.
        }
    }
    
    // 알고리즘 문제 풀이 시작
    return 0;
}