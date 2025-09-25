// https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    int coinChange(vector<int> &coins, int amt, int n, vector<vector<int>> &dp)
    {

        if (amt == 0)
            return 0;
        if (n == 0)
            return 1e8;

        if (dp[n][amt] != -1)
            return dp[n][amt];
        if (amt >= coins[n - 1])
        {
            return dp[n][amt] = min(1 + coinChange(coins, amt - coins[n - 1], n, dp),
                                    coinChange(coins, amt, n - 1, dp));
        }
        else
        {
            return dp[n][amt] = coinChange(coins, amt, n - 1, dp);
        }
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 2, vector<int>(amount + 2, -1));

        int ans = coinChange(coins, amount, coins.size(), dp);
        if (ans == 1e8)
            return -1;
        return ans;
    }
};