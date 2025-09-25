#include <bits/stdc++.h>
using namespace std;

int main() { return 0; }
// User function Template for C++

class Solution {
public:
  int mcm(int i, int j, int arr[]) {

    if (i >= j)
      return 0;

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {

      int curr =
          mcm(i, k, arr) + mcm(k + 1, j, arr) + arr[i - 1] * arr[k] * arr[j];
      ans = min(ans, curr);
    }

    return ans;
  }
  int matrixMultiplication(int N, int arr[]) {
    // code here
    return mcm(1, N - 1, arr);
  }
};
