// https://leetcode.com/problems/longest-ideal-subsequence/discuss/2390512/JavaC%2B%2BPython-DP
// DP

class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[150] = {}, ans = 0;
        for(auto &i : s) {
            int cur = 0;
            for(int j = i - k; j <= i + k; j++)
                cur = max(cur, dp[j] + 1);
            ans = max(ans, dp[i] = cur);
        }
        return ans;
    }
};
