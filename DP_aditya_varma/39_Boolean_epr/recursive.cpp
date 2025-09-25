#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int j, string s, bool isTrue)
{
    if (i > j)
        return 0;

    if (i == j)
    {
        if (isTrue)
            return s[i] == 'T';
        return s[i] == 'F';
    }

    int temp = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lt = solve(i, k - 1, s, true);
        int lf = solve(i, k - 1, s, false);

        int rt = solve(k + 1, j, s, true);
        int rf = solve(k + 1, j, s, false);

        if (s[k] == '&')
        {
            if (isTrue)
            {
                temp += lt * rt;
            }
            else
            {
                temp += lf * rt + lf * rf + rf * lt;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue)
            {
                temp += rt * lt + lt * rf + lf * rt;
            }
            else
                temp += lf * rf;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
            {
                temp += lf * rt + rf * lt;
            }
            else
            {
                temp += lt * rt + lf * rf;
            }
        }
    }
    return temp;

}

int main()
{
    string s;
    cin >> s;

    cout << solve(0, s.length() - 1, s, true);

    return 0;
}