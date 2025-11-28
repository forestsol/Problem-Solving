/***********************************************
 * 2025-11-25
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int arrMax = 100;
const int rMax = 1000;

int n, m, r;
int evenArr[arrMax][arrMax];
int oddArr[arrMax][arrMax];
int commands[rMax];
bool evenTurn = true;

void swap(){
    int temp = n;
    n = m;
    m = temp;
}

void input(){
    cin >> n >> m >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> evenArr[i][j];
        }
    }
    for(int i=0; i<r; i++){
        cin >> commands[i];
    }
}

void output(){
    if(evenTurn){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << evenArr[i][j] << " ";
            }
            cout << endl;
        }
    }else{
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << oddArr[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int section(int x, int y){
    if(x<n/2 && y<m/2){
        return 1;
    }else if(x<n/2 && y>=m/2){
        return 2;
    }else if(x>=n/2 && y>=m/2){
        return 3;
    }else if(x>=n/2 && y<m/2){
        return 4;
    }
    cout << "error!" << endl;
    return 999;
}

void op1(int (*src)[arrMax], int (*dst)[arrMax]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dst[i][j] = src[n-1-i][j];
        }
    }
}

void op2(int (*src)[arrMax], int (*dst)[arrMax]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dst[j][i] = src[j][m-1-i];
        }
    }
}

void op3(int (*src)[arrMax], int (*dst)[arrMax]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dst[i][j] = src[n-1-j][i];
        }
    }
    swap();
}

void op4(int (*src)[arrMax], int (*dst)[arrMax]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dst[i][j] = src[j][m-1-i];
        }
    }
    swap();
}

void op5(int (*src)[arrMax], int (*dst)[arrMax]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int sec = section(i, j);
            switch(sec){
                case 1:
                    dst[i][j] = src[i+n/2][j];
                    break;
                case 2:
                    dst[i][j] = src[i][j-m/2];
                    break;
                case 3:
                    dst[i][j] = src[i-n/2][j];
                    break;
                case 4:
                    dst[i][j] = src[i][j+m/2];
                    break;
            }
        }
    }
}

void op6(int (*src)[arrMax], int (*dst)[arrMax]){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int sec = section(i, j);
            switch(sec){
                case 1:
                    dst[i][j] = src[i][j+m/2];
                    break;
                case 2:
                    dst[i][j] = src[i+n/2][j];
                    break;
                case 3:
                    dst[i][j] = src[i][j-m/2];
                    break;
                case 4:
                    dst[i][j] = src[i-n/2][j];
                    break;
            }
        }
    }
}

void exec(){
    for(int i = 0; i<r; i++){
        int (*src)[arrMax];
        int (*dst)[arrMax];

        if(evenTurn){
            src = evenArr;
            dst = oddArr;
        }else{
            src = oddArr;
            dst = evenArr;
        }
        int command = commands[i];
        switch (command){
            case 1:
                op1(src, dst);
                break;
            case 2:
                op2(src, dst);
                break;
            case 3:
                op3(src, dst);
                break;
            case 4:
                op4(src, dst);
                break;
            case 5:
                op5(src, dst);
                break;
            case 6:
                op6(src, dst);
                break;
            default:
                cout << "error!" << endl;
                break;
        }
        evenTurn = !evenTurn;
    }
}

void solution(){
    input();
    exec();
    output();
}

int main() {
    fastio;
    solution();
    // 알고리즘 문제 풀이 시작
    return 0;
}