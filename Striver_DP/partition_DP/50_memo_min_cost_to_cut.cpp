#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
class Solution
{
    int rec(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (j < i)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e8;
        for (int ind = i; ind <= j; ind++)
        {

            int curr = cuts[j + 1] - cuts[i - 1] + rec(i, ind - 1, cuts, dp) + rec(ind + 1, j, cuts, dp);
            ans = min(ans, curr);
        }

        return dp[i][j] = ans;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {

        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        int m = cuts.size();
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));

        return rec(1, m - 2, cuts, dp);
    }
};