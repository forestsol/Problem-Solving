/***********************************************
 * 2025-05-09
 ***********************************************/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t-- > 0){
        int logs;
        cin >> logs; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int error_cnt = 0;
        for(int i = 0; i < logs; ++i){
            string s;
            getline(cin, s);
            if(s.length() > 100){ // 네번째 조건. 로그의 길이는 100을 넘지 않음.
                error_cnt++;
                continue;
            }
            vector<string> splitlog = split(s, " "); // 세번째 조건. 공백으로 나뉘어 들어감.
            /* 잘 들어가는지 테스트용
            for(string temp : splitlog){ 
                cout << temp << endl;
            }
            */
            if(splitlog.size() != 12){ // 첫번째 조건. 갯수가 다 안맞으면 애초에 이상한 로그임.
                error_cnt++;
                continue;
            }
            else{
                if(splitlog[0] != "line_name" || splitlog[1] != ":" || splitlog[3] != "product_name" || splitlog[4] != ":" || splitlog[6]!= "error_level" || splitlog[7] != ":" || splitlog[9] != "message" || splitlog[10] != ":"){
                    error_cnt++;
                    continue;
                }
                else{
                    string appendstring = splitlog[2];
                    appendstring += splitlog[5];
                    appendstring += splitlog[8];
                    appendstring += splitlog[11];
                    

                    for(int j = 0 ; j < appendstring.length(); ++j){
                        char thischar = appendstring[j];
                        if((thischar >= 'A' && thischar <='Z') || (thischar >= 'a' && thischar <= 'z')){}
                        else{
                            error_cnt++;
                            break;
                        }
                    }
                }
            }

        }
        cout << error_cnt << endl;
    }
    // 알고리즘 문제 풀이 시작
    return 0;
}