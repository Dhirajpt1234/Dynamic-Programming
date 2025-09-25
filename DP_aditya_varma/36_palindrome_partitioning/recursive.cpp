#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j)
{
    while (j > i)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
int pp(string s, int i, int j)
{
    if (i >= j)
        return 0;

    if (isPalindrome(s, i, j))
        return 0;

    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = pp(s, i, k) + pp(s, k + 1, j) + 1;
        mn = min(mn, temp);
    }

    return mn;
}

int main()
{
    string s;
    cin >> s;

    int n = s.length();

    cout << pp(s, 0, n - 1);

    return 0;
}