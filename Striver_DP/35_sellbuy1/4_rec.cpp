#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int idx, int buy, int k, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (idx >= n || k == 0)
            return 0;

        if (dp[idx][buy][k] != -1)
            return dp[idx][buy][k];

        if (buy)
        {
            return dp[idx][buy][k] = max(-(prices[idx]) + solve(idx + 1, 0, k, n, prices, dp),
                                         0 + solve(idx + 1, 1, k, n, prices, dp));
        }
        else
        {
            return dp[idx][buy][k] = max(prices[idx] + solve(idx + 1, 1, k - 1, n, prices, dp),
                                         0 + solve(idx + 1, 0, k, n, prices, dp));
        }
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solve(0, 1, k, n, prices, dp);
    }
};