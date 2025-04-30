#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {  0,  0, -1,  1, -2,  2, -3,  3,  0, -1,  1 };
int dy[] = { -1,  1,  0,  0,  0,  0,  0,  0, -2, -1, -1 };

bool is_moveable(int cur_x, int cur_y, int next_x, int next_y, vector<vector<char>>& rock_wall)
{
    if(abs(cur_x - next_x) + abs(cur_y - next_y) == 1)
        return true;

    if(cur_x == next_x)
    {
        if(rock_wall[cur_y - 1][cur_x] != '.')
            return false;
    }
    else if(cur_y == next_y)
    {
        if(cur_x > next_x)
            swap(cur_x, next_x);

        for(int i = cur_x + 1; i < next_x; ++i)
        {
            if(rock_wall[cur_y][i] != '.')
                return false;
        }
        for(int i = cur_x; i <= next_x; ++i)
        {
            if(cur_y - 1 < 0)
                return false;

            if(rock_wall[cur_y - 1][i] != '.')
                return false;
        }
    }
    else
    {
        if(cur_x < next_x)
        {
            if(rock_wall[cur_y][cur_x + 1] != '.' || rock_wall[cur_y - 1][cur_x] != '.')
                return false;
        }
        else
        {
            if(rock_wall[cur_y][cur_x - 1] != '.' || rock_wall[cur_y - 1][cur_x] != '.')
                return false;
        }
    }

    return true;
}

int main(void)
{
    int t;
    cin >> t;

    while(t --> 0)
    {
        int n;
        cin >> n;

        vector<vector<char>> rock_wall(n, vector<char>(n));
        vector<vector<int>> trace(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                char hold;
                cin >> hold;

                rock_wall[i][j] = hold;

                if(hold == 'H')
                    trace[i][j] = -1;
            }
        }

        queue<pair<int, int>> q;
        q.push({0, n - 1});
        visited[n - 1][0] = true;
        trace[n - 1][0] = 1;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 11; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;

                if(rock_wall[ny][nx] != 'H')
                    continue;

                if(visited[ny][nx])
                    continue;

                if(is_moveable(x, y, nx, ny, rock_wall) == false)
                    continue;

                visited[ny][nx] = true;
                if(rock_wall[ny][nx] == 'H')
                    trace[ny][nx] = trace[y][x] + 1;
                
                q.push({nx, ny});
            }
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
                cout << trace[i][j] << " ";

            cout << endl;
        }
    }
    
    return 0;
}