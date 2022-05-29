// https://leetcode.com/problems/steps-to-make-array-non-decreasing/discuss/2085864/Python-Stack-%2B-DP-%2B-Explanation
// stack + DP

class Solution {
public:
    int totalSteps(vector<int>& A) {
        int n = A.size(), ans = 0;
        vector<int> stack, dp(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!stack.empty() && A[i] > A[stack.back()]) {
                dp[i] = max(++dp[i], dp[stack.back()]);
                stack.pop_back();
                ans = max(ans, dp[i]);
            }
            stack.push_back(i);
        }
        return ans;
    }
};
