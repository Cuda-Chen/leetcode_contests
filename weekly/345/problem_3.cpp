class Solution {
public:
    int maxMoves(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                if(j == 0) {
                    continue;
                } else {
                    int a = (i - 1 >= 0 && j - 1 >= 0 && g[i - 1][j - 1] < g[i][j]) ? dp[i - 1][j - 1] : 0;
                    int b = (i >= 0 && j - 1 >= 0 && g[i][j - 1] < g[i][j]) ? dp[i][j - 1] : 0;
                    int c = (i + 1 < m && j - 1 >= 0 && g[i + 1][j - 1] < g[i][j]) ? dp[i + 1][j - 1] : 0;
                    int tmp = max({a, b, c});
                    dp[i][j] += tmp > 0 ? (tmp + 1) : 0;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++)
                ans = max(ans, dp[i][j]);
        }
        return ans == 0 ? ans : ans - 1;
    }
};
