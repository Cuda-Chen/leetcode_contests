// https://leetcode.com/problems/sum-of-matrix-after-queries/solutions/3594928/last-query-wins/

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& qs) {
        long long ans = 0, cnt[2] = {n, n};
        bool seen[2][10001] = {};
        for(int i = qs.size() - 1; i >= 0; i--) {
            int type = qs[i][0], id = qs[i][1], v = qs[i][2];
            if(!seen[type][id]) {
                seen[type][id] = true;
                ans += v * cnt[!type];
                --cnt[type];
            }
        }
        return ans;
    }
};
