#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    // basic logic is after sorting the arr , if no is divisible by pre no then its obv divisible by
    vector<int> largestDivisibleSubset(vector<int> &arr)
    {
        // algo approach
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<int> dp(n, 1);
        vector<int> lis(n, -1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    lis[i] = j;
                }
            }
        }

        int mx = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (dp[mx] < dp[i])
                mx = i;
        }

        vector<int> temp;
        int k = mx;
        while (k >= 0)
        {
            temp.push_back(arr[k]);
            k = lis[k];
        }

        for (int i = 0; i < temp.size() / 2; i++)
        {
            swap(temp[i], temp[temp.size() - 1 - i]);
        }

        // print(arr);
        // print(dp);
        // print(lis);
        // print(temp);

        return temp;
    }
};