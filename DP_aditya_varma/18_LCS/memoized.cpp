#include <bits/stdc++.h>
using namespace std;

int dp[50][50];
int lcs(string x, int n, string y, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (x[n - 1] == y[m - 1])
        dp[n][m] = 1 + lcs(x, n - 1, y, m - 1);
    else
        dp[n][m] = max(lcs(x, n, y, m - 1), lcs(x, n - 1, y, m));

    return dp[n][m];
}

int main()
{

    string x, y;
    cin >> x >> y;

    int n = x.length();
    int m = y.length();

    // initialization
    for (int i = 0; i < 51; i++)
    {
        for (int j = 0; j < 51; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }

    cout << lcs(x, n, y, m);

    return 0;
}

class Solution
{
public:
    int solve(string &a, string &b, int n, int m, vector<vector<int>> &dp)
    {

        if (n == 0 || m == 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];

        if (a[n - 1] == b[m - 1])
        {
            return dp[n][m] = 1 + solve(a, b, n - 1, m - 1, dp);
        }
        else
        {
            return dp[n][m] = max(solve(a, b, n - 1, m, dp), solve(a, b, n, m - 1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(text1, text2, n, m, dp);
    }
};