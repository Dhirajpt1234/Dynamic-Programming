#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp)
{
    if (j < 0 || j >= n)
        return 1e9;
    if (i == 0)
        return matrix[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int dl = matrix[i][j] + rec(i - 1, j - 1, matrix, n, dp);
    int d = matrix[i][j] + rec(i - 1, j, matrix, n, dp);
    int dr = matrix[i][j] + rec(i - 1, j + 1, matrix, n, dp);

    return dp[i][j] = min({dl, d, dr});
}

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, rec(n - 1, i, matrix, n, dp));
        }

        return ans;
    }
};