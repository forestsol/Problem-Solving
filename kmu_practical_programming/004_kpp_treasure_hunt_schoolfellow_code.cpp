#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        bool visited[52][52][4] = {false};
        char posit[52][52][4];   
        cin >> n;
        for(int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin >> posit[i][j];
            }
        }
        int y=0, x=0;
        int prev = 2;
        while(true){        
            if(visited[y][x][prev] == true) break;
            else visited[y][x][prev] = true;     
            char curr = posit[y][x][0];
            if(curr == 'B') prev = (prev + 2)%4;
            else if(curr == 'F') prev = (prev + 0)%4;
            else if(curr == 'R') prev = (prev + 3)%4;
            else if(curr == 'L') prev = (prev + 1)%4;


            int move = posit[y][x][1] - '0';
            if(prev == 0) y += move;
            else if(prev == 1) x -= move;
            else if(prev == 2) y -= move;
            else if(prev == 3) x += move;
            
        }
        cout << y << " " << x << "\n";
    }
    return 0;
}