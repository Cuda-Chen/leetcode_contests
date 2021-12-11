// https://leetcode.com/problems/detonate-the-maximum-bombs/discuss/1623383/easy-to-understand(-Directed-Graph-%2B-DFS)
// directed graph + DFS

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        for(int i = 0; i < bombs.size(); i++) {
            double r = bombs[i][2] * 1.0;
            long x = bombs[i][0], y = bombs[i][1];
            for(int j = 0; j < bombs.size(); j++) {
                if(i == j) continue;
                long a = bombs[j][0], b = bombs[j][1];
                double distance = sqrt((x - a) * (x - a) + (y - b) * (y - b));
                if(distance <= r) 
                    g[i].push_back(j);
            }
        }
        int ans = 1;
        for(int i = 0; i < bombs.size(); i++) {
            temp = 0;
            vector<bool> visited(bombs.size(), false);
            dfs(i, visited);
            ans = max(ans, temp);
        }
        return ans;
    }
    
    void dfs(int cur, vector<bool> &visited) {
        visited[cur] = true;
        temp++;
        for(int u : g[cur]) {
            if(visited[u]) continue;
            dfs(u, visited);
        }
    }
    
    int temp;
    unordered_map<int, vector<int>> g;
};
