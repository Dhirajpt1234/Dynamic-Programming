#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> &arr, int i, int j)
{
    if (i >= j)
        return 0;

    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        mn = min(mn, temp);
    }
    return mn;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << mcm(arr, 1, arr.size() - 1) << endl;

    return 0;
}