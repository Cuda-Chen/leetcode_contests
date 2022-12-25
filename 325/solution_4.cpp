// https://leetcode.com/problems/number-of-great-partitions/solutions/2948009/java-c-python-knapsack-problem/
// knapsack problem

class Solution {
public:
    int countPartitions(vector<int>& A, int k) {
        long mod = 1e9 + 7, total = 0, ans = 1;
        vector<long> dp(k);
        dp[0] = 1;
        for(int &a : A) {
            for(int i = k - 1 - a; i >= 0; i--)
                dp[i + a] = (dp[i + a] + dp[i]) % mod;
            ans = ans * 2 % mod;
            total += a;
        }
        for(int i = 0; i < k; i++)
            ans -= total - i < k ? dp[i] : dp[i] * 2;
        return (ans % mod + mod) % mod;
    }
};
