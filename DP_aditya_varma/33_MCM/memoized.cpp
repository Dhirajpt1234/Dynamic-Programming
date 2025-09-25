#include <bits/stdc++.h>
using namespace std;
int dp[11][11];

void print(int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int mcm(vector<int> &arr, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        mn = min(mn, temp);
    }

    return dp[i][j] = mn;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (i == 0 || i >= j)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = -1;
            }
        }
    }

    cout << mcm(arr, 1, n - 1) << endl;

    print(n);

    return 0;
}