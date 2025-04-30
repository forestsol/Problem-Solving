#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 0, 1, 0}; // 북 동 남 서
int dy[4] = {0, 1, 0, -1};

int cleanRoom(int n, int r, int c, int d, vector<vector<int>>& room)
{
    vector<vector<bool>> cleaned(n, vector<bool>(n, false));
    int cleaned_count = 0;

    while (true)
    {
        if (!cleaned[r][c])
        {
            cleaned[r][c] = true;
            cleaned_count++;
        }

        bool found = false;

        for (int i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (room[nr][nc] == 0 && !cleaned[nr][nc])
            {
                r = nr;
                c = nc;
                found = true;
                break;
            }
        }

        if (!found)
        {
            int back = (d + 2) % 4;
            int br = r + dx[back];
            int bc = c + dy[back];

            if (room[br][bc] == 1)
            {
                break;
            }
            else
            {
                r = br;
                c = bc;
            }
        }
    }

    return cleaned_count;
}

int main()
{
    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++)
    {
        int n, d;
        cin >> n >> d;

        int r, c;
        cin >> r >> c;

        vector<vector<int>> room(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> room[i][j];
            }
        }

        cout << cleanRoom(n, r, c, d, room) << endl;
    }

    return 0;
}
