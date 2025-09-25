#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int n = s.length();
    int dp[n + 1][n + 1];

    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    int mxr = 0, mxc = 0, mxl = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == s[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                
            }
            else
                dp[i][j] = 0;
        }
    }

    return 0;
}