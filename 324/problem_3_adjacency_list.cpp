// Adapted from: https://cs.stackexchange.com/questions/135300/graph-add-at-most-2-edges-to-make-all-graph-nodes-degree-even
// adjacency list
// You have to use hash map to represent adjacency list or you will get TLE on LeetCode OJ (n == 10^5).

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        int odd = 0;
        vector<int> odd_v;
        for(auto e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 0; i < n; i++) {
            int deg = g[i].size();
            if(deg % 2 == 1) {
                odd++;
                odd_v.push_back(i);
            }
        }
        
        if(odd == 0) {
            return true;
        } else if(odd == 2) {
            int a = odd_v[0], b = odd_v[1];
            for(int k = 0; k < n; k++) {
                if(!f(g, a, k) && !f(g, b, k)) {
                    return true;
                }
            }
            return false;
        } else if(odd == 4) {
            int a = odd_v[0], b = odd_v[1], c = odd_v[2], d = odd_v[3];
            if((!f(g, a, b) && !f(g, c, d)) ||
               (!f(g, a, c) && !f(g, b, d)) ||
               (!f(g, a, d) && !f(g, b, c)))
                return true;
            return false;
        }
        return false;
    }
    
private:
    bool f(unordered_map<int, vector<int>> &g, int u, int v) {
        for(auto x : g[u]) {
            if(x == v)
                return true;
        }
        return false;
    }
};
