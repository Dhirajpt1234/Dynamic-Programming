#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX - 1

int main()
{
    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int dp[n + 1][101];
    for (int j = 0; j < 101; j++)
        dp[0][j] = inf;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int j = 1; j < 101; j++)
    {
        if (j % coins[0] == 0)
            dp[1][j] = j / coins[0];
        else
            dp[1][j] = inf;
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            if (j >= coins[i - 1])
            {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    while (true)
    {
        int sum = 0;
        cin >> sum;

        cout << dp[n][sum];
    }

    return 0;
}