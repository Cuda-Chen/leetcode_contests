// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/solutions/2808897/dp-dp/
// DP + DP
// We precompute a 2d array pal that tells us whether a string between i and j is a palindrome (pal[i][j] == true).
// This is the same DP approach as for 647. Palindromic Substrings.
// Then, we use DP to find maximum number of splits.

class Solution {
public:
    int maxPalindromes(string s, int k) {
        if(k == 1)
            return s.size();
        for(int len = 1; len <= s.size(); len++) {
            for(int i = 0, j = i + len - 1; j < s.size(); i++, j++)
                pal[i][j] = (len < 3 ? true : pal[i + 1][j - 1]) && (s[i] == s[j]);
        }
        return dfs(0, k, s);
    }
    
private:
    int dp[2001] = {};
    bool pal[2001][2001] = {};
    
    int dfs(int i, int k, string &s) {
        if(i >= s.size())
            return 0;
        if(!dp[i]) {
            dp[i] = 1 + dfs(i + 1, k, s);
            for(int j = i + k - 1; j < s.size(); j++) {
                if(pal[i][j])
                    dp[i] = max(dp[i], 2 + dfs(j + 1, k, s));
            }
        }
        return dp[i] - 1;
    }
};
