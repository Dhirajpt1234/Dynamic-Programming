//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

int dp[30][200];
#define ll long long
const int mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;

    int cnt = 0;
    for (int j = 0; j < sum + 1; j++)
        dp[0][j] = 0;
    dp[0][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        if (arr[i - 1] == 0) // in the array there are zeroes also hence we cant just retun when sm == 0 , we can still go when sm == 0 as with sm = 0 , 0 will still give ans
        {
            cnt++;
        }
        dp[i][0] = pow(2, cnt);
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (j >= arr[i - 1])
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % mod;
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

/*

6 10
2 3 5 6 8 10

*/