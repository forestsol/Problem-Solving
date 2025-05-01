#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dc[] = {0, 1, 0, -1};
int dr[] = {-1, 0, 1, 0};

int main(void)
{
    int t;
    cin >> t;

    while(t --> 0)
    {
        int n, d;
        cin >> n >> d;
        vector<vector<int>> room(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n));

        int r, c;
        cin >> r >> c;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin >> room[i][j];
        }

        int result = 0;
        while(true)
        {
            if(!visited[r][c])
            {
                visited[r][c] = true;
                result++;
            }
            bool found = false;
            for(int i=0; i<4; i++)
            {
                d = (d + 3) % 4;

                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && room[nr][nc] == 0 && !visited[nr][nc])
                {
                    r = nr;
                    c = nc;
                    found = true;

                    break;
                }
            }

            if(found)
                continue;

            int back_d = (d + 2) % 4;
            int br = r + dr[back_d];
            int bc = c + dc[back_d];

            if(br >= 0 && br < n && bc >= 0 && bc < n && room[br][bc] == 0)
            {
                r = br;
                c = bc;
            }
            else
                break;
        }

        cout << result << endl;
    }
    return 0;
}