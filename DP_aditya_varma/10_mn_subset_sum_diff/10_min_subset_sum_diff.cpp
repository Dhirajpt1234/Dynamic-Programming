#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    int sm = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sm += arr[i];
    }

    bool dp[n + 1][sm + 1];
    // initialization
    for (int j = 0; j < sm + 1; j++)
        dp[0][j] = false;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;

    // choice diag
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sm + 1; j++)
        {
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int half = sm / 2;
    half++;
    while (half--)
    {
        if (dp[n][half])
        {
            cout << sm << " " << half << " " << sm - half << endl;
            return 0;
        }
    }
    cout << "NO";

    return 0;
}