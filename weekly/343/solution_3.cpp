// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/solutions/3468350/c-priority-queue-dp/
// priority queue (Dijkstra)

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int sx = start[0], sy = start[1], tx = target[0], ty = target[1];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = specialRoads.size();
        vector<int> dp(n, INT_MAX);
        for(int i = 0; i < n; i++)
            pq.emplace(abs(tx - specialRoads[i][2]) + abs(ty - specialRoads[i][3]), i);
        while(!pq.empty()) {
            auto [cost, i] = pq.top();
            pq.pop();
            if(dp[i] != INT_MAX)
                continue;
            dp[i] = min(dp[i], cost);
            for(int j = 0; j < n; j++) {
                if(j == i)
                    continue;
                pq.emplace(cost + specialRoads[i][4] + abs(specialRoads[j][2] - specialRoads[i][0]) + abs(specialRoads[j][3] - specialRoads[i][1]), j);
            }
        }
        int ans = abs(sx - tx) + abs(sy - ty);
        for(int i = 0; i < n; i++)
            ans = min(ans,
                     abs(sx - specialRoads[i][0]) + abs(sy - specialRoads[i][1]) + specialRoads[i][4] + dp[i]);
        return ans;
    }
};
