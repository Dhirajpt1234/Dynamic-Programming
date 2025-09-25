#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x;
    cin >> x;

    int n = x.length();
    int m = n;
    string y = "";
    for (int i = n - 1; i >= 0; i--)
        y.push_back(x[i]);

    int dp[n + 1][m + 1];
    for (int j = 0; j < m + 1; j++)
        dp[0][j] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            { // dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = 0;
            }
        }
    }

    string ans = "";

    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    cout << "A   ";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;

    for (int i = 0; i < n + 1; i++)
    {
        if (i == 0)
            cout << "  ";
        else
            cout << y[i - 1] << " ";
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans << endl;

    return 0;
}