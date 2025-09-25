#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    bool isPre(string &s, string &t)
    {
        int n = s.size();
        int m = t.size();

        if (n <= m || ((n - m) > 1))
            return false;
        int f = 1;
        int i = 0, j = 0;
        while (i < m + 1 && j < m)
        {
            if (s[i] == t[j])
                i++, j++;
            else
            {
                if (f)
                {
                    f = 0;
                    i++;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }

    void print(vector<int> &arr)
    {
        for (auto it : arr)
            cout << it << " ";
        cout << endl;
    }

    void print(vector<string> &arr)
    {
        for (auto it : arr)
            cout << it << " ";
        cout << endl;
    }

    void print(vector<pair<int, string>> &arr)
    {
        for (auto it : arr)
            cout << it.second << " ";
        cout << endl;
    }

    int longestStrChain(vector<string> &words)
    {

        int n = words.size();

        vector<pair<int, string>> arr(n);
        for (int i = 0; i < n; i++)
        {
            string s = words[i];
            arr[i].first = s.length();
            arr[i].second = words[i];
        }
        sort(arr.begin(), arr.end());

        vector<int> dp(n, 1);

        int mx = 1;
        for (int i = 1; i < n; i++)
        {
            // cout<<'\n'<<i<<"-->";
            for (int j = 0; j < i; j++)
            {
                if (isPre(arr[i].second, arr[j].second))
                {
                    // cout<<j<<" ";
                    dp[i] = max(dp[i], 1 + dp[j]);
                    mx = max(mx, dp[i]);
                }
            }
        }

        // cout<<endl;
        // print(dp);

        return mx;
    }
};