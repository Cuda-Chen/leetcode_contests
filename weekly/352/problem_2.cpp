class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if(n < 3)
            return {};
        
        vector<int> dp(n, 1);
        dp[0] = dp[1] = 0;
        for(int i = 2; i <= sqrt(n); i++) {
            if(!dp[i])
                continue;
            for(int j = i * i; j < n; j += i)
                dp[j] = 0;
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i <= n / 2; i++) {
            if(!dp[i])
                continue;
            
            int comp = n - i;
            if(dp[comp])
                ans.push_back({i, comp});
        }
        return ans;
    }
};
