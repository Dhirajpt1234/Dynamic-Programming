#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int idx, int buy, int k, int n, vector<int> &prices)
    {
        if (idx >= n || k == 0)
            return 0;

        if (buy)
        {
            return max(-(prices[idx]) + solve(idx + 1, 0, k, n, prices),
                       0 + solve(idx + 1, 1, k, n, prices));
        }
        else
        {
            return max(prices[idx] + solve(idx + 1, 1, k - 1, n, prices),
                       0 + solve(idx + 1, 0, k, n, prices));
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return solve(0, 1, 2, n, prices);
    }

    
};