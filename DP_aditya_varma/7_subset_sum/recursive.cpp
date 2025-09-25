// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

bool sub(vector<int> &arr, int sum, int n)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }

    if (sum >= arr[n - 1])
    {
        return sub(arr, sum - arr[n - 1], n - 1) || sub(arr, sum, n - 1);
    }
    else
    {
        return sub(arr, sum, n - 1);
    }
}

int main()

{
    vector<int> arr = {2, 3, 7, 5, 8};
    int sum = 21;

    if (sub(arr, sum, arr.size()))
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
    return 0;
}