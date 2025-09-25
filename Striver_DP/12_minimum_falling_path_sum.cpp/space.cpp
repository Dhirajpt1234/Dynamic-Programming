#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<int> curr(n, 0), prev(n, 0);

        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            prev[j] = matrix[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int dl = INT_MAX;
                if (j - 1 >= 0)
                    dl = matrix[i][j] + prev[j - 1];

                int d = matrix[i][j] + prev[j];

                int dr = INT_MAX;
                if (j + 1 < n)
                    dr = matrix[i][j] + prev[j + 1];

                curr[j] = min({dl, d, dr});
            }
            prev = curr;
        }

        for (int col = 0; col < n; col++)
        {
            ans = min(ans, prev[col]);
        }

        return ans;
    }
};