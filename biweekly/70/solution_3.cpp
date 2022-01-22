// https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/discuss/1709654/With-explanation-or-BFS-or-C%2B%2B
// BFS + sorting

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& price, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans, res;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        vector<int> d{0, 1, 0, -1, 0};
        int dist = 0;
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto p = q.front();
                q.pop();
                if(seen[p.first][p.second]) continue;
                if(grid[p.first][p.second] == 0) continue;
                seen[p.first][p.second] = true;
                if(grid[p.first][p.second] != -1) {
                    int val = grid[p.first][p.second];
                    if(val >= price[0] && val <= price[1])
                        res.push_back({dist, val, p.first, p.second});
                }
                for(int l = 0; l < 4; l++) {
                    int row = p.first + d[l], col = p.second + d[l + 1];
                    if(row >= 0 && row < m && col >= 0 && col < n)
                        q.push({row, col});
                }
            }
            dist++;
        }
        
        sort(res.begin(), res.end());
        for(int i = 0; i < min(int(k), int(res.size())); i++)
            ans.push_back({res[i][2], res[i][3]});
        return ans;
    }
};
