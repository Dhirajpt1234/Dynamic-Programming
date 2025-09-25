#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int rec(string a, string b, int n1, int n2, vector<vector<int>> &dp)
    {
        if (n1 == 0)
            return dp[n1][n2] = n2;
        if (n2 == 0)
            return dp[n1][n2] = n1;

        if (dp[n1][n2] != -1)
            return dp[n1][n2];

        if (a[n1 - 1] == b[n2 - 1])
            return dp[n1][n2] = rec(a, b, n1 - 1, n2 - 1, dp);
        else
        {
            return dp[n1][n2] = 1 + min(
                                        rec(a, b, n1 - 1, n2 - 1, dp), min(
                                                                           rec(a, b, n1 - 1, n2, dp), rec(a, b, n1, n2 - 1, dp)));
        }
    }

public:
    int minDistance(string a, string b)
    {
        int n1 = a.size();
        int n2 = b.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return rec(a, b, n1, n2, dp);
    }
};