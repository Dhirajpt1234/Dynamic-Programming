#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

bool isPalindrome(string s, int i, int j)
{
    while (j > i)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

int pp(string s, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (isPalindrome(s, i, j))
        return dp[i][j] = 0;

    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = pp(s, i, k) + pp(s, k + 1, j) + 1;
        mn = min(mn, temp);
    }

    return dp[i][j] = mn;
}

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i >= j)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }

    cout << pp(s, 0, n - 1);
    return 0;
}