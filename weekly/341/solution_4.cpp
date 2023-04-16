// https://leetcode.com/problems/minimize-the-total-price-of-the-trips/solutions/3421847/c-dfs-comments/?q=C%2B%2B&orderBy=most_relevant
// DFS

class Solution {
public:
    vector<int> demand = vector<int>(100);
    unordered_map<int, vector<int>> g;
    
    int isInPath(int u, int dst, int p = -1) {
        if(u == dst) {
            demand[dst]++;
            return 1;
        }
        for(auto v : g[u]) {
            if(v == p)
                continue;
            if(isInPath(v, dst, u)) {
                demand[u]++;
                return 1;
            }
        }
        return 0;
    }
    
    pair<int, int> minNonAdjPath(int u, int p, vector<int> &price) {
        int use = (price[u] / 2) * demand[u];
        int dont_use = price[u] * demand[u];
        
        for(auto v : g[u]) {
            if(v == p)
                continue;
            pair<int, int> ans = minNonAdjPath(v, u, price);
            dont_use += min(ans.first, ans.second);
            use += ans.second;
        }
        return {use, dont_use};
    }
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        for(auto e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        for(auto t : trips) {
            int u = t[0], v = t[1];
            isInPath(u, v);
        }
        
        pair<int, int> ans = minNonAdjPath(0, -1, price);
        return min(ans.first, ans.second);
    }
};
