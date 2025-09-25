#include <bits/stdc++.h>
using namespace std;

int main() { return 0; }
class Solution {
  int rec(int i, int j, vector<int> &cuts) {
    if (j < i)
      return 0;

    int ans = 1e8;
    for (int ind = i; ind <= j; ind++) {

      int curr = cuts[j + 1] - cuts[i - 1] + rec(i, ind - 1, cuts) +
                 rec(ind + 1, j, cuts);
      ans = min(ans, curr);
    }

    return ans;
  }

public:
  int minCost(int n, vector<int> &cuts) {

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    int m = cuts.size();
    sort(cuts.begin(), cuts.end());

    return rec(1, m - 2, cuts);
  }
};