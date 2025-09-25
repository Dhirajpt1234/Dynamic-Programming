#include <bits/stdc++.h>
using namespace std;

int main() { return 0; }

#define ll long long

class Solution {
public:
  int solve(int i, int j, vector<int> &arr) {

    if (i > j)
      return 0;

    ll ans = INT_MIN;

    for (int k = i; k <= j; k++) {
      ll curr = 1LL * arr[i - 1] * arr[k] * arr[j + 1] + solve(i, k - 1, arr) +
                solve(k + 1, j, arr);
      ans = max(ans, curr);
    }

    return ans;
  }
  int maxCoins(vector<int> &nums) {
    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    int n = nums.size();

    return solve(1, n - 2, nums);
  }
};