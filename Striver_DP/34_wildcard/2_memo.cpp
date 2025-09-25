#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int n, int m, string &a, string &b, vector<vector<int>> &dp)
    {

        if (n <= 0 && m <= 0)
            return true;
        if (m <= 0)
            return false;
        if (n <= 0)
        {
            for (int i = 1; i <= m; i++)
            {
                if (b[i - 1] != '*')
                    return false;
            }
            return true;
        }

        if (dp[n][m] != -1)
            return dp[n][m];

        bool ans = false;
        if (a[n - 1] == b[m - 1] || b[m - 1] == '?')
        {

            ans = solve(n - 1, m - 1, a, b, dp);
        }
        else if (b[m - 1] == '*')
        {
            ans = solve(n, m - 1, a, b, dp) || solve(n - 1, m, a, b, dp);
        }
        else
            ans = false;

        return dp[n][m] = ans;
        
    }
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, s, p, dp);
    }
};