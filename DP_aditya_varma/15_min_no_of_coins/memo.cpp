//https://leetcode.com/problems/coin-change-ii/description/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    int solve(vector<int> &coins, int amt, int n, vector<vector<int>> &dp)
    {

        if (n <= 0)
        {
            if (amt == 0)
                return 1;
            return 0;
        }

        if (dp[n][amt] != -1)
            return dp[n][amt];

        // if can
        if (amt >= coins[n - 1])
        {
            return dp[n][amt] = solve(coins, amt - coins[n - 1], n, dp) + solve(coins, amt, n - 1, dp);
        }
        else
        {
            return dp[n][amt] = solve(coins, amt, n - 1, dp);
        }
    }
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return solve(coins, amount, n, dp);
    }
};