#include <vector>
#include <numeric> // For std::accumulate
#include <cmath>   // For std::abs
#include <algorithm> // For std::min

class Solution {
public:
    int minDifference(std::vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        // dp[i][j] will be true if sum j is possible with first i items
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(totalSum + 1, false));

        // Base case: A sum of 0 is always possible with any number of items (by picking none)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= totalSum; j++) {
                // If current element arr[i-1] is greater than the target sum j,
                // we can't include it. The result depends on the previous i-1 elements.
                if (arr[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // We have two choices:
                    // 1. Don't include arr[i-1]: result is dp[i-1][j]
                    // 2. Include arr[i-1]: result is dp[i-1][j - arr[i-1]]
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        // Now, find the minimum difference
        // We only need to check the last row of the DP table up to totalSum / 2
        // to find all possible sums for the first set (s1).
        int minDiff = totalSum; // Initialize with the maximum possible difference

        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            // If a subset with sum s1 is possible using all n elements...
            if (dp[n][s1]) {
                // The other set's sum (s2) will be totalSum - s1
                // The difference is s2 - s1 = (totalSum - s1) - s1 = totalSum - 2 * s1
                minDiff = std::min(minDiff, totalSum - 2 * s1);
            }
        }

        return minDiff;
    }
};