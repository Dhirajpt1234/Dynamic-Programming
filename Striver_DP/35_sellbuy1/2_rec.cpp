#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int idx, int buy, int n, vector<int> &prices)
    {

        if (idx >= n)
            return 0;

        if (buy)
        {
            return max(-(prices[idx]) + solve(idx + 1, 0, n, prices), // if we buy it now
                       0 + solve(idx + 1, 1, n, prices));             // if we dont buy it now.
        }
        else
        {
            return max(prices[idx] + solve(idx + 1, 1, n, prices), // if we sell it now.
                       0 + solve(idx + 1, 0, n, prices));          // if we dont sell it now.
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        return solve(0, 1, n, prices);
    }
};
