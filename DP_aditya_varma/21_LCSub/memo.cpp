#include <bits/stdc++.h>
using namespace std;

int main() { return 0; }

class Solution {
public:
  int solve(string a, string b, int n, int m, vector<vector<int>> &dp) {

    if (n == 0 || m == 0)
      return 0;

    if (dp[n][m] != -1)
      return dp[n][m];

    if (a[n - 1] == b[m - 1]) {
      dp[n][m] = 1 + solve(a, b, n - 1, m - 1, dp);
    } else {
      dp[n][m] = 0;
    }

    return dp[n][m];
  }

  int longestCommonSubstr(string a, string b, int n, int m) {
    // your code here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int mx = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {

        mx = max(mx, solve(a, b, i, j, dp));
      }
    }
    return mx;
  }
};