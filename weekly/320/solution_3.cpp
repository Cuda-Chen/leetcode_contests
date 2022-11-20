// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/solutions/2831660/dfs/
// DFS

class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> al(roads.size() + 1);
        for(auto &r : roads) {
            al[r[0]].push_back(r[1]);
            al[r[1]].push_back(r[0]);
        }
        long long ans = 0;
        return dfs(0, -1, 0, seats, al, ans);
    }
    
private:
    long long dfs(int i, int prev, int depth, int seats, vector<vector<int>> &al, long long &ans) {
        long long riders = 1;
        for(int j : al[i])
            if(j != prev)
                riders += dfs(j, i, depth + 1, seats, al, ans);
        if(depth == 0)
            return ans;
        ans += (riders / seats) * depth + (riders % seats ? 1 : 0);
        return riders % seats;
    }
};
