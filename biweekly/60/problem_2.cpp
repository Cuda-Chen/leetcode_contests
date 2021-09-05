// Find All Groups of Farmland
// DFS

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans;
        vector<vector<pair<int, int>>> sets;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(land[i][j] == 1 && !visited[i][j]) {
                    vector<pair<int, int>> singleSet;
                    dfs(i, j, m, n, land, visited, singleSet);
                    cout << singleSet.size() << " ";
                    sort(begin(singleSet), end(singleSet), [](const auto &a, const auto &b) {
                        if(a.second == b.second)
                            return a.first < b.first;
                        return a.second < b.second;
                    });
                    sets.push_back(singleSet);
                }
            }
        }
        
        
        if(sets.empty()) return {};
        
        for(auto a : sets) {
            ans.push_back({a.front().first, a.front().second, a.back().first, a.back().second});
        }
            
        return ans;
    }
    
private:
    void dfs(int i, int j, int m, int n, vector<vector<int>>& land, vector<vector<bool>> &visited, vector<pair<int, int>> &singleSet) {
        if(i < 0 || j < 0 || i >= m || j >= n || land[i][j] == 0 || visited[i][j])
            return;
        
        visited[i][j] = true;
        singleSet.push_back({i, j});
        dfs(i + 1, j, m, n, land, visited, singleSet);
        dfs(i - 1, j, m, n, land, visited, singleSet);
        dfs(i, j + 1, m, n, land, visited, singleSet);
        dfs(i, j - 1, m, n, land, visited, singleSet);
    }
};
