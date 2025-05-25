/***********************************************
 * 2025-05-16
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'



int main() {
    fastio;
    int t;
    cin >> t;
    while(t-- > 0){
        int n; // 메세지수
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        queue<unsigned long long int> A;
        queue<unsigned long long int> B;

        unsigned long long int totalA = 0;
        unsigned long long int totalB = 0;
        for(int i = 0; i < n; ++i){
            string ordermsg;
            getline(cin, ordermsg);
            if(ordermsg[0] == 'O'){
                string stringnum = ordermsg.substr(6, ordermsg.length()-8);
                long long ordernum = stoi(stringnum);
                if(ordermsg[ordermsg.length()-1] == 'A'){
                    A.push(ordernum);
                    totalA = totalA + ordernum;
                }
                else if(ordermsg[ordermsg.length()-1] == 'B'){
                    B.push(ordernum);
                    totalB = totalB + ordernum;
                }
                else if(ordermsg[ordermsg.length()-1] == 'C'){
                    if(totalA > totalB){
                        B.push(ordernum);
                        totalB = totalB + ordernum;
                    }
                    else{
                        A.push(ordernum);
                        totalA = totalA + ordernum;
                    }
                }
            }
            else if(ordermsg[0] == 'D'){
                if(ordermsg[ordermsg.length()-1] == 'A'){
                    unsigned long long int delval = A.front();
                    totalA = totalA - delval;
                    A.pop();
                }
                else if(ordermsg[ordermsg.length()-1] == 'B'){
                    unsigned long long int delval = B.front();
                    totalB = totalB - delval;
                    B.pop();
                }
            }

        }
        cout << totalA << ' ' << totalB << endl;
    }
    return 0;
}