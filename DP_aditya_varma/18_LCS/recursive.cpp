#include <bits/stdc++.h>
using namespace std;

int lcs(string x, int n, string y, int m) {
  if (n == 0 || m == 0)
    return 0;

  if (x[n - 1] == y[m - 1]) {
    return 1 + lcs(x, n - 1, y, m - 1);
  } else {
    return max(lcs(x, n - 1, y, m), lcs(x, n, y, m - 1));
  }
}

int main() {
  string x, y;
  cin >> x >> y;

  int n = x.length();
  int m = y.length();

  cout << lcs(x, n, y, m);

  return 0;
}