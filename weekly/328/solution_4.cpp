// https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/solutions/3052985/c-dfs-beats-100/
// DFS

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for(auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        long long ans = 0;
        function<vector<long long>(int, int)> dfs = [&](int now, int pre) {
            // cur_max[0]: max pathsum
            // cur_max[1]: max (pathsum - endpoint)
            vector<long long> cur_max = {price[now], 0};
            for(auto &v : g[now]) {
                if(v != pre) {
                    auto &&sub = dfs(v, now);
                    ans = max(ans, (long long)cur_max[0] + sub[1]);
                    ans = max(ans, (long long)cur_max[1] + sub[0]);
                    cur_max[0] = max(cur_max[0], sub[0] + price[now]);
                    cur_max[1] = max(cur_max[1], sub[1] + price[now]);
                }
            }
            return cur_max;
        };
        dfs(0, -1);
        return ans;
    }
};
