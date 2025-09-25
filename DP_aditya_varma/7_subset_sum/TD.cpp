#include <bits/stdc++.h>
using namespace std;

int t[21][101];

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // initialization.
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

    cout << "Hii";

    // actual code
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            if (t[i][j] != -1)
                continue;

            if (j >= arr[i - 1])
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    while (true)
    {
        int sum = 0;
        cin >> sum;

        cout << t[n][sum] << endl;
    }

    return 0;
}

/*



*/