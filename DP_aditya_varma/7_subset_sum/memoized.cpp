#include <bits/stdc++.h>
using namespace std;

int t[21][101];

void print()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------\n";
}

int sub(vector<int> &arr, int sum, int n)
{
    cout << n << " " << sum << endl;
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    if (t[n][sum] != -1)
    {
        cout << 3 << endl;
        return t[n][sum];
    }
    if (sum >= arr[n - 1])
    {
        cout << 1 << endl;
        return t[n][sum] = sub(arr, sum - arr[n - 1], n - 1) || sub(arr, sum, n - 1);
    }
    else
    {
        cout << 2 << endl;
        return t[n][sum] = sub(arr, sum, n - 1);
    }
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

    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (i == 0 && j == 0)
                t[i][j] = 1;
            else if (i == 0)
                t[i][j] = 0;
            else if (j == 0)
                t[i][j] = 1;
            else
                t[i][j] = -1;
        }
    }

    // print();

    while (true)
    {
        cout << "Enter the sum : ";
        int sum;
        cin >> sum;

        if (sub(arr, sum, arr.size()) == 1)
            cout << "TRUE\n";
        else
            cout << "FALSE\n";

        // print();
    }

    return 0;
}