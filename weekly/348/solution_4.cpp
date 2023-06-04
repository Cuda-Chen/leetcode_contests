// DP (top-down)

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        return dfs(0, 0, min_sum, max_sum, num2, true, true, dp2)
            - dfs(0, 0, min_sum, max_sum, num1, true, false, dp1);
    }
    
private:
    int dp1[23][401][2] = {}, dp2[23][401][2] = {};
    int mod = 1e9 + 7;
    
    int dfs(int i, int sum, int min_sum, int max_sum, const string &num, bool lim, bool equal, int dp[23][401][2]) {
        if(i == num.size() || sum > max_sum)
            return sum >= min_sum && sum <= max_sum && (equal || !lim);
        if(dp[i][sum][lim] == 0) {
            dp[i][sum][lim] = 1;
            for(int n = 0; n <= (lim ? num[i] - '0' : 9); n++)
                dp[i][sum][lim] = (dp[i][sum][lim] +
                                  dfs(i + 1, sum + n, min_sum, max_sum, num, lim && (n == num[i] - '0'), equal, dp)) % mod;
        }
        return dp[i][sum][lim] - 1;
    }
};
