// https://leetcode.com/problems/selling-pieces-of-wood/discuss/2168148/JavaC%2B%2BPython-Bottom-Up-DP
// DP

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(201, vector<long long>(201));
        for(auto &p : prices)
            dp[p[0]][p[1]] = p[2];
        
        for(int w = 1; w <= m; w++) {
            for(int h = 1; h <= n; h++) {
                for(int a = 1; a <= w / 2; a++)
                    dp[w][h] = max(dp[w][h], dp[a][h] + dp[w - a][h]);
                for(int a = 1; a <= h / 2; a++)
                    dp[w][h] = max(dp[w][h], dp[w][a] + dp[w][h - a]);
            }
        }
        
        return dp[m][n];
    }
};
