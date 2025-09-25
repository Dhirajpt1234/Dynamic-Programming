#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
class Solution
{
public:
    int solve(int idx, int prev, int n, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (idx >= n)
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int ans = 0;
        if (prev == -1 || arr[idx] > arr[prev])
        {
            ans = max(
                1 + solve(idx + 1, idx, n, arr, dp),
                solve(idx + 1, prev, n, arr, dp));
        }
        else
        {
            ans = solve(idx + 1, prev, n, arr, dp);
        }
        return dp[idx][prev + 1] = ans;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, -1, n, nums, dp);
    }
};