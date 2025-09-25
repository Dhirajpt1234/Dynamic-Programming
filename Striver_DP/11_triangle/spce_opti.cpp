#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int m = triangle[0].size();

    vector<int> curr(n);

    for (int j = 0; j < n; j++)
    {
        curr[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> temp(n);
        for (int j = i; j >= 0; j--)
        {
            int down = triangle[i][j] + curr[j];
            int down_right = triangle[i][j] + curr[j + 1];

            temp[j] = min(down, down_right);
        }
        curr = temp;
    }

    return curr[0];
}
int main()
{

    return 0;
}