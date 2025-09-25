#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
class Solution
{
public:
    int solve(int idx, int k, int n, vector<int> &arr, vector<int> &dp)
    {
        if (idx >= n)
            return 0;

        int mx = 0;
        int ans = 0;
        if (dp[idx] != -1)
            return dp[idx];

        for (int i = idx; i < n && i < idx + k; i++)
        {
            mx = max(mx, arr[i]);
            int curr = (i - idx + 1) * mx + solve(i + 1, k, n, arr, dp);
            ans = max(ans, curr);
        }

        return dp[idx] = ans;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();

        vector<int> dp(n, -1);
        return solve(0, k, n, arr, dp);
    }
};