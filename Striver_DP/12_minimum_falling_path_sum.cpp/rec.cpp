#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> &matrix, int n)
{
    if (j < 0 || j >= n)
        return 1e9;
    if (i == 0)
        return matrix[i][j];

    int dl = matrix[i][j] + rec(i - 1, j - 1, matrix, n);
    int d = matrix[i][j] + rec(i - 1, j, matrix, n);
    int dr = matrix[i][j] + rec(i - 1, j + 1, matrix, n);

    return min({dl, d, dr});
}

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, rec(n - 1, i, matrix, n));
        }

        return ans;
    }
};