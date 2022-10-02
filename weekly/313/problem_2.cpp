// simulation

class Solution {
public:
    int maxSum(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        int ans = 0;
        
        for(int i = 0; i < m - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                int tmp = (g[i][j] + g[i][j + 1] + g[i][j + 2])
                    + g[i + 1][j + 1]
                    + (g[i + 2][j] + g[i + 2][j + 1] + g[i + 2][j + 2]);
                ans = max(ans, tmp);
            }
        }
        
        return ans;
    }
};
