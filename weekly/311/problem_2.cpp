// DP (bottom-up)

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        vector<int> dp(n, 1);

        for(int i = 1; i < n; i++) {
            if(s[i] - s[i - 1] == 1)
                dp[i] += dp[i - 1];
        }

        return *max_element(begin(dp), end(dp));
    }
};
