#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, y;
  cin >> x >> y;

  int n = x.length();
  int m = y.length();

  int dp[n + 1][m + 1];
  for (int j = 0; j < m + 1; j++)
    dp[0][j] = 0;
  for (int i = 0; i < n + 1; i++)
    dp[i][0] = 0;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      if (x[i - 1] == y[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  string ans = "";

  int i = n, j = m;

  while (i > 0 && j > 0) {
    if (x[i - 1] == y[j - 1]) {
      ans.push_back(x[i - 1]);
      i--;
      j--;
    } else {
      if (dp[i - 1][j] > dp[i][j - 1]) {
        i--;
      } else {
        j--;
      }
    }
  }

  sort(ans.begin(), ans.end());

  string scs = "";

  i = 0, j = 0;
  int k = 0;
  while (k < ans.length()) {
    if (x[i] == ans[k] && y[j] == ans[k]) {
      scs.push_back(ans[k]);
      i++;
      j++;
      k++;
    } else {
      while (x[i] != ans[k]) {
        scs.push_back(x[i]);
        i++;
      }

      while (y[j] != ans[k]) {
        scs.push_back(y[j]);
        j++;
      }
    }
  }

  while (i < x.length()) {
    scs.push_back(x[i]);
    i++;
  }
  while (j < y.length()) {
    scs.push_back(y[j]);
    j++;
  }

  cout << scs << endl;

  return 0;
}