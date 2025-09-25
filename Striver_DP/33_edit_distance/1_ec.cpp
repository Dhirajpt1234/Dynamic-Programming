#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int rec(string a, string b, int n1, int n2)
    {
        if (n1 == 0)
            return n2;
        if (n2 == 0)
            return n1;

        if (a[n1 - 1] == b[n2 - 1])
            return rec(a, b, n1 - 1, n2 - 1);
        else
        {
            return 1 + min(
                           rec(a, b, n1 - 1, n2 - 1), min(
                                                          rec(a, b, n1 - 1, n2), rec(a, b, n1, n2 - 1)));
        }
    }

public:
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();

        return rec(word1, word2, n1, n2);
    }
};