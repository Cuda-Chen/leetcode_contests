class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                unordered_set<int> tl, br;
                for(int ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--)
                    tl.insert(g[ii][jj]);
                for(int ii = i + 1, jj = j + 1; ii < m && jj < n; ii++, jj++)
                    br.insert(g[ii][jj]);
                //cout << tl.size() << " " << br.size() << endl;
                int tmp = tl.size() - br.size();
                ans[i][j] = abs(tmp);
            }
        }
        return ans;
    }
};
