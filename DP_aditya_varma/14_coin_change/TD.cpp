#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    int dp[n + 1][101];

    for (int j = 0; j < 101; j++)
        dp[0][j] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            if (j >= coins[i - 1])
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    while (true)
    {
        int sum = 0;
        cin >> sum;

        cout << dp[n][sum] << endl;
    }

    return 0;
}