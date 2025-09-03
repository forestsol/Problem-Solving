    /***********************************************
     * 2025-09-02
     ***********************************************/

    #include <bits/stdc++.h>
    using namespace std;

    #define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #define endl '\n'

    int main() {
        fastio;
        // 알고리즘 문제 풀이 시작
        cout.precision(16);
        cout << fixed;
        double result = -1;
        vector<double> tri;
        tri.resize(3);
        double ax, ay, bx, by, cx, cy;
        cin >> ax >> ay >> bx >> by >> cx >> cy;
        
        if((by-ay)*(cx-ax) != (cy-ay)*(bx-ax)){
            tri[0] = sqrt(pow(ax-bx, 2) + pow(ay-by, 2));
            tri[1] = sqrt(pow(bx-cx, 2) + pow(by-cy, 2));
            tri[2] = sqrt(pow(cx-ax, 2) + pow(cy-ay, 2));
            sort(tri.begin(), tri.end());
            result = 2*(tri[2]+tri[1]) - 2*(tri[1]+tri[0]);
        }

        cout << result << endl;
        
        return 0;
    }