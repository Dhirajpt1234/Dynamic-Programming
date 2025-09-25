#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> length(n), price(n);
    for (int i = 0; i < n; i++)
        length[i] = i + 1;
    for (int i = 0; i < n; i++)
        cin >> price[i];

    int dp[n + 1][101];
    for (int j = 0; j < 101; j++)
        dp[0][j] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < 101; j++)
        {
            if (j >= length[i - 1])
            {
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    while (true)
    {
        int len;
        cin >> len;

        cout << dp[n][len] << endl;
    }
    return 0;
}