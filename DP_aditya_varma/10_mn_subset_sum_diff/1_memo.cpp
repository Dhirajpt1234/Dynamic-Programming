#include <bits/stdc++.h>
using namespace std;

int main() { return 0; }

class Solution {

public:
  int solve(int n, int sm, int arr[], vector<vector<int>> &dp) {
    if (n == 0) {
      return sm;
    }

    if (dp[n][sm] != -1)
      return dp[n][sm];
    // pick
    if (sm >= arr[n - 1]) {
      return dp[n][sm] = min(solve(n - 1, sm - arr[n - 1], arr, dp),
                             solve(n - 1, sm, arr, dp));
    } else {
      return dp[n][sm] = solve(n - 1, sm, arr, dp);
    }
  }

  int minDifference(int arr[], int n) {
    int sm = 0;
    for (int i = 0; i < n; i++) {
      sm += arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(sm / 2 + 5, -1));
    int a = solve(n, sm / 2, arr, dp);
    int s1 = sm / 2 - a;

    return sm - (2 * s1);

    // s1 + s2 = sum;
    // diff = s2  - s1
    // but diff = (sum - s1 ) - s1;
    // diff = sum - 2* s1

    // we can calculate s1 by calculating min diff from sum/2
  }
};
