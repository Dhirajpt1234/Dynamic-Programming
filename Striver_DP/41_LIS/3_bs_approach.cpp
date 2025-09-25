#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    int lengthOfLIS(vector<int> &arr)
    {
        // binary search approach
        int n = arr.size();

        int len = 1;
        vector<int> temp;

        temp.push_back(arr[0]);

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > temp.back())
            {
                temp.push_back(arr[i]);
                len++;
            }
            else
            {
                int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[idx] = arr[i];
            }
        }

        return len;
    }
};