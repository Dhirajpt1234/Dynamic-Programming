#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
#define ll long long

class Solution
{
public:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        ll ans = INT_MIN;

        for (int k = i; k <= j; k++)
        {
            ll curr = 1LL * arr[i - 1] * arr[k] * arr[j + 1] + solve(i, k - 1, arr, dp) + solve(k + 1, j, arr, dp);
            ans = max(ans, curr);
        }

        return dp[i][j] = ans;
    }
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, n - 2, nums, dp);
    }
};