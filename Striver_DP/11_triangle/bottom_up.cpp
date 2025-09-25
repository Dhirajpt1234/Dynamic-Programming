#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{

    if (i == n - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + rec(i + 1, j, triangle, n, dp);
    int down_right = triangle[i][j] + rec(i + 1, j + 1, triangle, n, dp);

    return min(down, down_right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int m = triangle[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + dp[i + 1][j];
            int down_right = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down , down_right);
        }
    }

    return dp[0][0];
}
