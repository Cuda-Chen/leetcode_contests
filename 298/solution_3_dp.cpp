// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/discuss/2168227/JavaC%2B%2BPython-One-Pass-O(n)
// DP

class Solution {
public:
    int longestSubsequence(string s, int k) {
        vector<int> dp(1010);
        int j = 0;
        for(char &v : s) {
            if(dp[j] * 2 + v - '0' <= k)
                dp[++j] = dp[j] * 2 + v - '0';
            for(int i = j; i > 0; i--)
                dp[i] = min(dp[i], dp[i - 1] * 2 + v - '0');
        }
        return j;
    }
};
