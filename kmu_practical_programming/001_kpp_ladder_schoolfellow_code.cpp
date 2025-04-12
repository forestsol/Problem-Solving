#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
    int t;
    cin >> t;

    while(t --> 0)
    {
        int n, m, d;
        cin >> n >> m >> d;

        vector<string> ladder(m + 1);
        for(int i=0; i<m; i++)
        {
            string l;
            getline(cin >> ws, l);
            ladder[i] = l;
        }

        d = (d - 1) * 2;
        int y = m - 1;

        while(y >= 0)
        {
            if(d - 1 >= 0 && ladder[y][d - 1] == '+')
            {
                d-=2;
                y--;
            }
            else if(d + 1 <= n*2 && ladder[y][d + 1] == '+')
            {
                d+=2;
                y--;
            }
            else
            {
                y--;
            }
        }
        cout << d / 2 + 1 << endl;
    }

    return 0;
}