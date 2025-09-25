#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    vector<int> lis(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        vector<int> maxi(n, 0);
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, dp[i]);
            maxi[i] = mx;
        }

        return maxi;
    }

    void print(vector<int> &arr)
    {
        for (auto it : arr)
            cout << it << " ";
        cout << endl;
    }
    int LongestBitonicSequence(vector<int> arr)
    {
        // code here
        int n = arr.size();

        vector<int> left = lis(arr);

        for (int i = 0; i < n / 2; i++)
        {
            swap(arr[i], arr[n - 1 - i]);
        }
        vector<int> right = lis(arr);
        for (int i = 0; i < n / 2; i++)
        {
            swap(right[i], right[n - 1 - i]);
        }
        for (int i = 0; i < n / 2; i++)
        {
            swap(arr[i], arr[n - 1 - i]);
        }

        // print(left);
        // print(right);

        int ans = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (ans < left[i] + right[i + 1])
            {
                ans = left[i] + right[i + 1];
                if (arr[i] == arr[i + 1])
                    ans--;
            }
        }

        return ans;
    }
};


/* 
next version problem : for practise 
https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

*/