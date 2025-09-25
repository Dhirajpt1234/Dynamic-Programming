#include <bits/stdc++.h>
using namespace std;

int rec(int i, int j, vector<vector<int>> &triangle, int n)
{

    if (i == n - 1)
        return triangle[i][j];

    int down = rec(i + 1, j, triangle, n);
    int down_right = rec(i + 1, j + 1, triangle, n);

    return min(down, down_right);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int m = triangle[0].size();

    return rec(0, 0, triangle , n);
}

int main()
{

    return 0;
}