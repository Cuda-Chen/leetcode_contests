// DFS

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        g = vector<vector<int>>(n);
        unordered_set<int> s(begin(restricted), end(restricted));
        for(auto e : edges) {
            int u = e[0], v = e[1];
            if(s.count(u) || s.count(v))
                continue;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        visit = vector<int>(n, 0);
        dfs(0);

        int ans = 0;
        for(int i : visit)
            if(i)
                ans++;
        return ans;
    }

private:
    vector<vector<int>> g;
    vector<int> visit;

    void dfs(int v) {
        visit[v] = 1;

        for(auto u : g[v])
            if(!visit[u])
                dfs(u);
    }
};
