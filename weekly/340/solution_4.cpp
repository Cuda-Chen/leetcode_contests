// https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/solutions/3395695/bfs-with-boundaries/
// BFS

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), steps = 0;
        vector<int> max_i(n), max_j(m);
        vector<pair<int, int>> q{{0, 0}}, q1;
        while(!q.empty()) {
            steps++;
            for(auto [i, j] : q) {
                if(i == m - 1 && j == n - 1)
                    return steps;
                for(int ii = max(max_i[j], i + 1); ii < m && ii - i <= g[i][j]; ii++)
                    q1.push_back({ii, j});
                for(int jj = max(max_j[i], j + 1); jj < n && jj - j <= g[i][j]; jj++)
                    q1.push_back({i, jj});
                max_i[j] = max(max_i[j], i + g[i][j]);
                max_j[i] = max(max_j[i], j + g[i][j]);
            }
            swap(q, q1);
            q1.clear();
        }
        return -1;
    }
};
