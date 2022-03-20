// https://leetcode.com/problems/maximum-points-in-an-archery-competition/discuss/1865714/JAVA-Knapsack-01
// DP (0-1 knapsack)

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<vector<int>> dp(13, vector<int>(numArrows + 1));
        for(int i = 0; i <= 12; i++) {
            for(int j = 0; j <= numArrows; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(j >= (aliceArrows[i - 1]) + 1)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - (aliceArrows[i - 1] + 1)] + (i - 1));
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        vector<int> ans(12);
        int result = dp[12][numArrows];
        int total = 0;
        for(int i = 12, j = numArrows; i > 0 && result > 0; i--) {
            if(result == dp[i - 1][j]) continue;
            else {
                // This item is included.
                ans[i - 1] = aliceArrows[i - 1] + 1;
                result -= (i - 1);
                j -= (aliceArrows[i - 1] + 1);
                total += aliceArrows[i - 1] + 1;
            }
        }
        
        // as bob has to fire numArrows, remaining can be 0
        if(total < numArrows)
            ans[0] = numArrows - total;
        return ans;
    }
};
