#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
// User function Template for C++

class Solution
{
public:
    int mcm(int i, int j, int arr[], vector<vector<int>> &dp)
    {

        if (i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int k = i; k < j; k++)
        {

            int curr = mcm(i, k, arr, dp) + mcm(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j];
            ans = min(ans, curr);
        }

        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return mcm(1, N - 1, arr, dp);
    }
};