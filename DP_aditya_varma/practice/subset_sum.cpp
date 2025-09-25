#include <bits/stdc++.h>
using namespace std;

int sub(vector<int> &arr, int sum, int n, vector<vector<int>> &dp) {
  if (sum == 0)
    return 1;
  if (sum <= 0 || n <= 0)
    return 0;

  if (dp[sum][n - 1] != -1)
    return dp[sum][n - 1];

  int ans = 0;
  if (sum >= arr[n - 1]) {
    ans = sub(arr, sum - arr[n - 1], n - 1, dp) || sub(arr, sum, n - 1, dp);
  } else {
    ans = sub(arr, sum, n - 1, dp);
  }

  return ans;
}

int main() {
  vector<int> arr = {2, 3, 7, 5, 8};
  int sum = 23;

  int n = arr.size();
  vector<vector<int>> dp(sum + 1, vector<int>(n, -1));

  if (sub(arr, sum, n, dp))
    cout << "TRUE\n";
  else
    cout << "FALSE\n";
  return 0;
}