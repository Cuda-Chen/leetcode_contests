// https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/solutions/3570296/java-c-python-dp-solution/
// DP

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        map<int, vector<int>> A;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                A[M[i][j]].push_back(i * n + j);
        }
        vector<vector<int>> dp(m, vector<int>(n));
        vector<int> ans(n + m);
        for(auto &[a, pos] : A) {
            for(int p : pos) {
                int i = p / n, j = p % n;
                dp[i][j] = max(ans[i], ans[m + j]) + 1;
            }
            for(int p : pos) {
                int i = p / n, j = p % n;
                ans[m + j] = max(ans[m + j], dp[i][j]);
                ans[i] = max(ans[i], dp[i][j]);
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};
