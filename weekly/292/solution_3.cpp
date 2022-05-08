// https://leetcode.com/problems/count-number-of-texts/discuss/2017730/CPP-or-Short-and-Simple-or-DP
// DP (top-down)

class Solution {
public:
    int countTexts(string pressedKeys) {
        int n = pressedKeys.size();
        vector<int> dp(n + 1, -1);
        return helper(pressedKeys, 0, n, dp);
    }
    
private:
    int mod = 1e9 + 7;
    
    int helper(string &s, int i, int n, vector<int> &dp) {
        if(i >= n) return 1;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        
        if(i + 1 < n && s[i] == s[i + 1]) {
            ans += helper(s, i + 2, n, dp);
            ans %= mod;
            if(i + 2 < n && s[i] == s[i + 2]) {
                ans += helper(s, i + 3, n, dp);
                ans %= mod;
                if(i + 3 < n && s[i] == s[i + 3] &&
                   (s[i] == '9' || s[i] == '7'))
                    ans += helper(s, i + 4, n, dp);
                ans %= mod;
            }
        } 
        ans += helper(s, i + 1, n, dp);
        ans %= mod;
        return dp[i] = ans;
    }
};
