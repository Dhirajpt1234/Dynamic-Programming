#include <bits/stdc++.h>
using namespace std;

int main() { return 0; }
class Solution {
public:
  int solve(int idx, int k, int n, vector<int> &arr) {
    if (idx >= n)
      return 0;

    int mx = 0;
    int ans = 0;

    for (int i = idx; i < n && i < idx + k; i++) {
      mx = max(mx, arr[i]);
      int curr = (i - idx + 1) * mx + solve(i + 1, k, n, arr);
      ans = max(ans, curr);
    }

    return ans;
  }

  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();

    return solve(0, k, n, arr);
  }
};