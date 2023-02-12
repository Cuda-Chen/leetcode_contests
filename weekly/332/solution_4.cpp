// https://leetcode.com/problems/subsequence-with-the-minimum-score/solutions/3174041/right-and-left-o-n/

class Solution {
public:
    int minimumScore(string s, string t) {
        int ss = s.size(), st = t.size(), k = st - 1;
        vector<int> dp(st, -1);
        for(int i = ss - 1; i >= 0 && k >= 0; i--)
            if(s[i] == t[k])
                dp[k--] = i;
        int ans = k + 1;
        for(int i = 0, j = 0; i < ss && j < st && ans > 0; i++) {
            if(s[i] == t[j]) {
                for(; k < t.size() && dp[k] <= i; k++);
                ans = min(ans, k - (++j));
            }
        }
        return ans;
    }
};
