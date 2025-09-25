#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{

    if (i == n - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = rec(i + 1, j, triangle, n, dp);
    int down_right = rec(i + 1, j + 1, triangle, n, dp);

    return min(down, down_right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int m = triangle[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return rec(0, 0, triangle, n, dp);
}

int main()
{

    return 0;
}