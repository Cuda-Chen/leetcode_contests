// https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/discuss/2198534/C%2B%2B-DFS-Simple
// DFS 

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), ans = INT_MAX;
        visited = vector<bool>(n);
        pc = vector<vector<int>>();
        adj = vector<vector<int>>(n);
        child_xor = vector<int>(n, 0);
        childs = vector<vector<bool>>(n, vector<bool>(n, false));
        this->nums = nums;
        par = vector<int>();
        
        for(vector<int> &edge : edges)
            adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);
        
        dfs(0);
        
        for(int i = 0; i < pc.size(); i++) {
            for(int j = i + 1; j < pc.size(); j++) {
                int a = pc[i][1], b = pc[j][1];
                int xa = child_xor[a], xb, xc = child_xor[0];
                
                if(childs[a][b]) {
                    xb = child_xor[b];
                    xc ^= xa;
                    xa ^= xb;
                } else {
                    xb = child_xor[b];
                    xc ^= xa;
                    xc ^= xb;
                }
                
                ans = min(max({xa, xb, xc}) - min({xa, xb, xc}), ans);
            }
        }
        
        return ans;
    }
    
private:
    vector<bool> visited;
    vector<vector<int>> pc, adj;
    vector<vector<bool>> childs;
    vector<int> child_xor, nums, par;
    
    int dfs(int i) {
        int ans = nums[i];
        visited[i] = true;
        
        for(int p : par)
            childs[p][i] = true;
        
        par.push_back(i);
        
        for(int child : adj[i])
            if(!visited[child]) {
                pc.push_back({i, child});
                ans ^= dfs(child);
            }
        par.pop_back();
        
        return child_xor[i] = ans;
    }
};
