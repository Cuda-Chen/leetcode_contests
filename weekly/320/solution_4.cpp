// https://leetcode.com/problems/number-of-beautiful-partitions/solutions/2831925/dp-standard-to-prefix-sum-optimization-o-k-n-2-to-o-k-n/
// DP + prefix sum

class Solution {
public:
    const long long mod = 1e9 + 7;
    unordered_set<char> p = {'2', '3', '5', '7'};
    
    bool isPrime(int x) {
        return (p.find(x) != p.end());
    }
    
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        vector<vector<long long>> dp(k + 1, vector<long long>(n, 0LL));
        for(int j = 0; j < n; j++)
            dp[1][j] = (isPrime(s[0]) && !isPrime(s[j]));
        vector<long long> previous_row(n, 0);
        for(int i = 0; i + 1 < n; i++) {
            if(isPrime(s[i + 1]))
                previous_row[i] = dp[1][i];
            if(i - 1 >= 0)
                previous_row[i] = (previous_row[i] + previous_row[i - 1]) % mod;
        }
        for(int i = 2; i <= k; i++) {
            vector<long long> current_row(n, 0LL);
            for(int end = (i * minLength) - 1; end < n; end++) {
                if(isPrime(s[end]))
                    continue;
                
                long long prefixsum = previous_row[end - minLength];
                int start = ((i - 1) * minLength) - 1;
                if(start - 1 >= 0)
                    prefixsum = (prefixsum - previous_row[start - 1] + mod) % mod;
                dp[i][end] = (dp[i][end] + prefixsum) % mod;
                
                if(end + 1 < n and isPrime(s[end + 1]))
                    current_row[end] = (current_row[end] + dp[i][end]) % mod;
            }
                for(int c = 1; c <= n - 1; c++)
                    current_row[c] = (current_row[c] + current_row[c - 1]) % mod;
                
                swap(previous_row, current_row);
            
        }
        return dp[k][n - 1];
    }
};
