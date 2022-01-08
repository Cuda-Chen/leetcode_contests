// WA

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> dp(26, vector<int>(26, 0));
        int ans = 0;
        for(auto w : words) {
            dp[w[0] - 'a'][w[1] - 'a'] += 1;
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(i == j) {
                    if(dp[i][j] % 2 == 0) {
                        ans += dp[i][j];  
                        dp[i][j] = 0;
                    } else {
                        if(dp[i][j] == 1) {
                            continue;
                        } else {
                            ans += 4 * (dp[i][j] / 2);
                            dp[i][j] %= 2;
                        }
                    }
                } else {
                    if(dp[i][j]) {
                        if(dp[j][i] >= 1) {
                            dp[j][i] -= 1;
                            ans += 4;
                            dp[i][j] -= 1;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 26; i++) {
            if(dp[i][i]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};
