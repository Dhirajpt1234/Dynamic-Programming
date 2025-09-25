#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool solve(int n, int m, string &a, string &b) {
    if (n <= 0 && m <= 0)
      return true;
    if (m <= 0)
      return false;
    if (n <= 0) {
      for (int i = 1; i <= m; i++) {
        if (b[i - 1] != '*')
          return false;
      }
      return true;
    }

    if (a[n - 1] == b[m - 1] || b[m - 1] == '?') {

      return solve(n - 1, m - 1, a, b);
    } else if (b[m - 1] == '*') {
      return solve(n, m - 1, a, b) || solve(n - 1, m, a, b);
    } else
      return false;
  }
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    return solve(n, m, s, p);
  }
};