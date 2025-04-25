#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int age;
    bool alive;
};

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int main()
{
    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++)
    {
        int n, c, k, p;
        cin >> n >> c >> k >> p;

        vector<vector<int>> nutrient(n, vector<int>(n));
        vector<vector<vector<Tree>>> board(n, vector<vector<Tree>>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> nutrient[i][j];
            }
        }

        for (int i = 0; i < c; i++)
        {
            int r, c, age;
            cin >> r >> c >> age;
            board[r][c].push_back({age, true});
        }

        for (int year = 0; year < p; year++)
        {
            vector<vector<int>> dead_nutrient(n, vector<int>(n, 0));
            vector<vector<Tree>> born[n];

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    sort(board[i][j].begin(), board[i][j].end(), [](Tree a, Tree b) {
                        return a.age < b.age;
                    });

                    vector<Tree> updated;

                    for (auto& tree : board[i][j])
                    {
                        if (nutrient[i][j] >= tree.age)
                        {
                            nutrient[i][j] -= tree.age;
                            tree.age++;
                            updated.push_back(tree);
                        }
                        else
                        {
                            dead_nutrient[i][j] += tree.age / 2;
                        }
                    }

                    board[i][j] = updated;
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    nutrient[i][j] += dead_nutrient[i][j];
                }
            }

            vector<pair<int, int>> spread;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (auto& tree : board[i][j])
                    {
                        if (tree.age % 5 == 0)
                        {
                            for (int d = 0; d < 8; d++)
                            {
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if (ni >= 0 && nj >= 0 && ni < n && nj < n)
                                {
                                    board[ni][nj].push_back({1, true});
                                }
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    nutrient[i][j] += k;
                }
            }
        }

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                total += board[i][j].size();
            }
        }

        cout << total << endl;
    }

    return 0;
}
