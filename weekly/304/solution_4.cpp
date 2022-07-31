// https://leetcode.com/problems/longest-cycle-in-a-graph/discuss/2357631/DFS
// DFS

class Solution {
public:
    int longestCycle(vector<int>& e) {
        int ans = -1;
        vector<pair<int, int>> m(e.size(), {-1, -1});
        for(int i = 0; i < e.size(); i++) {
            for(int j = i, dist = 0; j != -1; j = e[j]) {
                auto [dist_i, from_i] = m[j];
                if(dist_i == -1)
                    m[j] = {dist++, i};
                else {
                    if(from_i == i)
                        ans = max(ans, dist - dist_i);
                    break;
                }
            }
        }
        return ans;
    }
};
