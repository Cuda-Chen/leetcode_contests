// OJ: https://leetcode.com/contest/weekly-contest-282/problems/minimum-time-to-finish-the-race/
// Author: github.com/lzl124631x
// Time: O(N * numLaps)
// Space: O(numLaps)

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& A, int change, int numLaps) {
        int N = A.size(), len = 0;
        vector<long> best(numLaps, LONG_MAX), dp(numLaps + 1, INT_MAX);
        for(int i = 0; i < N; i++) {
            long f = A[i][0], r = A[i][1], sum = change, p = 1;
            for(int j = 0; j < numLaps; j++) {
                sum += f * p;
                if(f * p >= f + change) break;
                best[j] = min(best[j], sum);
                len = max(len, j + 1);
                p *= r;
            }
        }
        dp[0] = 0;
        for(int i = 0; i < numLaps; i++) {
            for(int j = 0; j < len && i - j >= 0; j++)
                dp[i + 1] = min(dp[i + 1], dp[i - j] + best[j]);
        }
        return dp[numLaps] - change;
    }
};
