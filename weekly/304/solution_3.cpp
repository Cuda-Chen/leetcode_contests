// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/discuss/2357694/Two-DFS
// two DFS

class Solution {
public:
    int closestMeetingNode(vector<int>& e, int node1, int node2) {
        int ans = -1, min_dist = INT_MAX;
        vector<int> m1(e.size(), -1), m2(e.size(), -1);
        for(int i = node1, dist = 0; i != -1 && m1[i] == -1; i = e[i])
            m1[i] = dist++;
        for(int i = node2, dist = 0; i != -1 && m2[i] == -1; i = e[i]) {
            m2[i] = dist++;
            if(m1[i] >= 0 && max(m1[i], m2[i]) <= min_dist) {
                ans = max(m1[i], m2[i]) == min_dist ? min(ans, i) : i;
                min_dist = max(m1[i], m2[i]);
            }
        }
        return ans;
    }
};
