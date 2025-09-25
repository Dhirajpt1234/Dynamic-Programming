#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  int sm = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sm += arr[i];
  }

  int dp[n + 1][sm + 1];

  for (int j = 0; j < sm + 1; j++)
    dp[0][j] = 0;
  for (int i = 0; i < n + 1; i++)
    dp[i][0] = 1;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < sm + 1; j++) {
      if (j >= arr[i - 1])
        dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < sm + 1; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  int diff = 0;
  cin >> diff;

  int s1 = (diff + sm) / 2;

  cout << dp[n][s1] << endl;
  return 0;
}