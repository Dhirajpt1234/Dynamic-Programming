#include <bits/stdc++.h>
using namespace std;

int main() { return 0; }

#define ll long long
const int mod = 1e9 + 7;

class Solution {

public:
  int solve(int n, int sm, int arr[], vector<vector<int>> &dp) {

    if (n == 0) // in the array there are zeroes also hence we cant just retun
                // when sm == 0 , we can still go when sm == 0 as with sm = 0 ,
                // 0 will still give ans
    {
      if (sm == 0)
        return 1;
      return 0;
    }

    if (dp[n][sm] != -1)
      return dp[n][sm];

    if (sm >= arr[n - 1]) {
      return dp[n][sm] = (solve(n - 1, sm - arr[n - 1], arr, dp) % mod +
                          solve(n - 1, sm, arr, dp) % mod) %
                         mod;
    } else {
      return dp[n][sm] = solve(n - 1, sm, arr, dp);
    }
  }
  int perfectSum(int arr[], int n, int sum) {
    // Your code goes here
    vector<vector<int>> dp(n + 2, vector<int>(sum + 2, -1));
    return solve(n, sum, arr, dp);
  }
};