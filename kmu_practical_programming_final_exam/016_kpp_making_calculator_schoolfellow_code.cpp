#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<string> tokens;
int idx;

string peek() {
    if (idx < (int)tokens.size()) return tokens[idx];
    return "";
}
string get() {
    return idx < (int)tokens.size() ? tokens[idx++] : "";
}

long long parseExpr();  

long long parseFactor() {
    string t = peek();
    if (t == "(") {
        get();                  
        long long v = parseExpr();
        get();                
        return v;
    }
  
    get();
    return stoll(t);
}

long long parseTerm() {
    long long v = parseFactor();
    while (true) {
        string op = peek();
        if (op == "*") {
            get();
            long long rhs = parseFactor();
            v = v * rhs;
        }
        else {
            break;
        }
    }
    return v;
}

long long parseExpr() {
    long long v = parseTerm();
    while (true) {
        string op = peek();
        if (op == "+" || op == "-") {
            get();
            long long rhs = parseTerm();
            if (op == "+") v = v + rhs;
            else            v = v - rhs;
        }
        else {
            break;
        }
    }
    return v;
}

int main() {
    fastio;

    int T;
    cin >> T;
    while (T--) {
        int L;
        cin >> L;             
       
        tokens.clear();
        idx = 0;
        cin.ignore(1, '\n');   
        string line;
        getline(cin, line);
       
        istringstream iss(line);
        string tk;
        while (iss >> tk) tokens.push_back(tk);

        long long result = parseExpr();
        cout << result << "\n";
    }
    return 0;
}