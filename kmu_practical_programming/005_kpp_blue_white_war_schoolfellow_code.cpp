#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int n, vector<vector<int>>& graph)
{
    vector<int> team(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (team[i] == -1)
        {
            queue<int> q;
            q.push(i);
            team[i] = 0;

            while (!q.empty())
            {
                int current = q.front();
                q.pop();

                for (int neighbor : graph[current])
                {
                    if (team[neighbor] == -1)
                    {
                        team[neighbor] = 1 - team[current];
                        q.push(neighbor);
                    }
                    else if (team[neighbor] == team[current])
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (isBipartite(n, graph))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}
