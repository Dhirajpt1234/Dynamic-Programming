#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool isValid(int j1, int j2, int m)
    {
        return j1 >= 0 && j1 < m && j2 >= 0 && j2 < m;
    }
    int help(int i, int j1, int j2, vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        if (i == n - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        int dj[] = {-1, 0, 1};

        int ans = 0;
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {

                int newj1 = j1 + dj[x];
                int newj2 = j2 + dj[y];

                if (isValid(newj1, newj2, m))
                {

                    if (j1 == j2)
                    {
                        int temp = grid[i][j1] + help(i + 1, newj1, newj2, grid);
                        ans = max(ans, temp);
                    }
                    else
                    {
                        int temp = grid[i][j1] + grid[i][j2] + help(i + 1, newj1, newj2, grid);
                        ans = max(ans, temp);
                    }
                }
            }
        }

        return ans;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        return help(0, 0, m - 1, grid);
    }
};