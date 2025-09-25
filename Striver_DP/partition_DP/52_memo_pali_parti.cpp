#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}
class Solution
{
public:
    bool isPali(string &s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    int solve(int idx, int n, string &s, vector<int> &dp)
    {

        if (idx >= n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];
        int ans = 1e7;

        for (int i = idx; i < n; i++)
        {
            if (isPali(s, idx, i))
            {
                ans = min(ans, solve(i + 1, n, s, dp));
            }
        }

        return dp[idx] = ans + 1;
    }
    int minCut(string s)
    {
        int n = s.size();
        if (n == 1)
            return 0;
        vector<int> dp(n + 1, -1);
        return solve(0, n, s, dp) - 1;
    }
};