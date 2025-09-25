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
        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int dl = INT_MAX;
                if (j - 1 >= 0)
                    dl = matrix[i][j] + dp[i - 1][j - 1];

                int d = matrix[i][j] + dp[i - 1][j];

                int dr = INT_MAX;
                if (j + 1 < n)
                    dr = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min({dl, d, dr});
            }
        }

        for (int col = 0; col < n; col++)
        {
            ans = min(ans, dp[n - 1][col]);
        }

        return ans;
    }
};